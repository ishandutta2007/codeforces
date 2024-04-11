#include <cstdio>
#include <algorithm>
typedef unsigned long long ull;
const int Maxn=18;
char mp[Maxn+5][Maxn+5];
int n;
ull f[Maxn+1][1<<Maxn|5],g[Maxn+1][1<<Maxn|5];
void FWT_and(ull *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				if(flag==1){
					a[j+k]+=a[i+j+k];
				}
				else{
					a[j+k]-=a[i+j+k];
				}
			}
		}
	}
}
void FWT_or(ull *a,int flag,int len){
	for(int i=1;i<len;i<<=1){
		for(int j=0;j<len;j+=(i<<1)){
			for(int k=0;k<i;k++){
				if(flag==1){
					a[i+j+k]+=a[j+k];
				}
				else{
					a[i+j+k]-=a[j+k];
				}
			}
		}
	}
}
int lis[Maxn+5];
ull ans[1<<Maxn|5];
int get_mask(int len){
	int pos=0;
	int ans=0;
	for(int i=1;i<=len;i++){
		ans|=((1<<lis[i])-1)<<pos;
		pos+=lis[i]+1;
	}
	return ans;
}
int get_lis(int mask){
	int len=0;
	for(int i=0,j;i<n;i=j+1){
		j=i;
		if(((mask>>i)&1)==0){
			continue;
		}
		while(j<n&&((mask>>j)&1)==1){
			j++;
		}
		j--;
		lis[++len]=j-i+1;
	}
	return len;
}
ull get_val(int len){
	static ull sum[1<<Maxn|5];
	for(int i=0;i<(1<<n);i++){
		sum[i]=0;
	}
	sum[0]=1;
	FWT_or(sum,1,(1<<n));
	int cur_sum=0;
	for(int i=1;i<=len;i++){
		for(int j=0;j<(1<<n);j++){
			sum[j]*=g[lis[i]+1][j];
		}
		cur_sum+=lis[i]+1;
	}
	cur_sum=n-cur_sum;
	while(cur_sum--){
		for(int i=0;i<(1<<n);i++){
			sum[i]*=g[1][i];
		}
	}
	FWT_or(sum,-1,1<<n);
	return sum[(1<<n)-1];
}
void work_dfs(int sum,int len,int last){
	last=std::min(last,sum);
	ans[get_mask(len-1)]=get_val(len-1);
	if(last==1){
		return;
	}
	for(int i=last;i>1;i--){
		lis[len]=i-1;
		work_dfs(sum-i,len+1,i);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",mp[i]);
	}
	g[0][0]=1;
	for(int i=0;i<n;i++){
		f[i][1<<i]=1;
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((~(i>>j)&1)||f[j][i]==0){
				continue;
			}
			for(int k=0;k<n;k++){
				if(((i>>k)&1)||mp[j][k]!='1'){
					continue;
				}
				f[k][i|(1<<k)]+=f[j][i];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			g[__builtin_popcount(j)][j]+=f[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		FWT_or(g[i],1,1<<n);
	}
	work_dfs(n,1,n);
	for(int i=0;i<(1<<(n-1));i++){
		int len=get_lis(i);
		std::sort(lis+1,lis+1+len,[&](int p,int q){return p>q;});
		int val=get_mask(len);
		if(val==i){
			continue;
		}
		ans[i]=ans[val];
	}
	FWT_and(ans,-1,1<<(n-1));
	for(int i=0;i<(1<<(n-1));i++){
		printf("%llu ",ans[i]);
	}
	puts("");
	return 0;
}