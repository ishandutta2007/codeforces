#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
int n;
int a[Maxn+5];
int f[20][Maxn+5];
int log_2[Maxn+5];
int maxn[Maxn+5];
void init(){
	for(int i=1;i<=n;i++){
		f[0][i]=a[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
	log_2[0]=-1;
	for(int i=1;i<=n;i++){
		log_2[i]=log_2[i>>1]+1;
	}
	maxn[n]=a[n];
	for(int i=n-1;i>0;i--){
		maxn[i]=max(maxn[i+1],a[i]);
	}
}
int query(int l,int r){
	int k=log_2[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		init();
		int tmp_max=0;
		int ans_1=-1,ans_2=-1,ans_3=-1;
		for(int i=1;i<=n;i++){
			tmp_max=max(tmp_max,a[i]);
			int left=i+1,right=n;
			while(left<right){
				int mid=(left+right+1)>>1;
				if(query(i+1,mid)>=tmp_max){
					left=mid;
				}
				else{
					right=mid-1;
				}
			}
			while(left-1>i&&query(i+1,left-1)==tmp_max&&a[left]==tmp_max){
				left--;
			}
			if(query(i+1,left)!=tmp_max){
				continue;
			}
			if(left+1<=n&&maxn[left+1]==tmp_max){
				ans_1=i;
				ans_2=left-i;
				ans_3=n-left;
				break;
			}
		}
		if(ans_1==-1){
			puts("NO");
		}
		else{
			puts("YES");
			printf("%d %d %d\n",ans_1,ans_2,ans_3);
		}
	}
	return 0;
}