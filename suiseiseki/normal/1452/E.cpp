#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=2000;
const int Mod=1000000007;
int n,m,k;
int l[Maxn+5],r[Maxn+5];
int f[Maxn+5][2];
int find_val(int l_1,int r_1,int l_2,int r_2){
	if(r_1<l_2||r_2<l_1){
		return 0;
	}
	return min(r_1,r_2)-max(l_1,l_2)+1;
}
void add(int h,int left,int right,int val){
	if(left<1){
		left=1;
	}
	if(right>n-k+1){
		right=n-k+1;
	}
	f[left][0]+=h-val;
	f[right+1][0]-=h-val;
	if(left>1){
		int st=left-(h-val);
		f[max(1,st)][1]++;
		f[left][1]--;
		f[max(1,st)][0]-=st;
		f[left][0]+=st;
	}
	int end=right+(h-val);
	f[right+1][1]--;
	if(end<=n-k+1){
		f[end][1]++;
	}
	f[right+1][0]+=(h-val-1)+(right+1);
	if(end<=n-k+1){
		f[end][0]-=(h-val-1)+(right+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	int ans=0;
	for(int x=1;x<=n-k+1;x++){
		int tmp_ans=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<2;j++){
				f[i][j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			int val=find_val(x,x+k-1,l[i],r[i]);
			tmp_ans+=val;
			if(val==min(r[i]-l[i]+1,k)){
				continue;
			}
			if(k<=r[i]-l[i]+1){
				add(k,l[i],r[i]-k+1,val);
			}
			else{
				add(r[i]-l[i]+1,r[i]-k+1,l[i],val);
			}
		}
		for(int y=1;y<=n-k+1;y++){
			for(int j=0;j<2;j++){
				f[y][j]+=f[y-1][j];
			}
			ans=max(ans,tmp_ans+f[y][0]+f[y][1]*y);
		}
	}
	printf("%d\n",ans);
    return 0;
}