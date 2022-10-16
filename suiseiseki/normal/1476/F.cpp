#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=300000;
const int Inf=0x3f3f3f3f;
int p[Maxn+5];
int n;
int f_max[19][Maxn+5];
int log_2[Maxn+5];
void init(){
	for(int i=2;i<=n;i++){
		log_2[i]=log_2[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		f_max[0][i]=i+p[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f_max[i][j]=max(f_max[i-1][j],f_max[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int l,int r){
	if(l>r){
		return -Inf;
	}
	int k=log_2[r-l+1];
	return max(f_max[k][l],f_max[k][r-(1<<k)+1]);
}
int f[Maxn+5],lst[Maxn+5];
char ans[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		f[i]=0;
	}
	init();
	lst[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1];
		lst[i]=i;
		if(f[i-1]>=i){
			f[i]=max(f[i],i+p[i]);
		}
		int left=0,right=i;
		while(left<right){
			int mid=(left+right)>>1;
			if(f[mid]>=i-p[i]-1){
				right=mid;
			}
			else{
				left=mid+1;
			}
		}
		if(left<i){
			int tmp=max(i-1,query(left+1,i-1));
			if(tmp>f[i]){
				lst[i]=left;
				f[i]=tmp;
			}
		}
	}
	if(f[n]<n){
		puts("NO");
	}
	else{
		puts("YES");
		int pos=n;
		while(pos){
			if(lst[pos]==pos){
				ans[pos]='R';
				pos--;
			}
			else{
				ans[pos]='L';
				for(int i=lst[pos]+1;i<pos;i++){
					ans[i]='R';
				}
				pos=lst[pos];
			}
		}
		for(int i=1;i<=n;i++){
			putchar(ans[i]);
		}
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}