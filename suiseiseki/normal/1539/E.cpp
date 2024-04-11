#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n,m;
int c[Maxn+5];
int a_l[Maxn+5],a_r[Maxn+5],b_l[Maxn+5],b_r[Maxn+5];
int f_l[Maxn+5][2],f_r[Maxn+5][2];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&c[i],&a_l[i],&a_r[i],&b_l[i],&b_r[i]);
	}
	f_l[n+1][0]=f_l[n+1][1]=0;
	f_r[n+1][0]=f_r[n+1][1]=m;
	for(int i=n;i>0;i--){
		if(a_l[i]<=c[i]&&c[i]<=a_r[i]){
			f_l[i][0]=b_l[i],f_r[i][0]=b_r[i];
			if(c[i]<f_l[i+1][1]||f_r[i+1][1]<c[i]){
				f_l[i][0]=std::max(f_l[i][0],f_l[i+1][0]);
				f_r[i][0]=std::min(f_r[i][0],f_r[i+1][0]);
			}
		}
		else{
			f_l[i][0]=m,f_r[i][0]=0;
		}
		if(b_l[i]<=c[i]&&c[i]<=b_r[i]){
			f_l[i][1]=a_l[i],f_r[i][1]=a_r[i];
			if(c[i]<f_l[i+1][0]||f_r[i+1][0]<c[i]){
				f_l[i][1]=std::max(f_l[i][1],f_l[i+1][1]);
				f_r[i][1]=std::min(f_r[i][1],f_r[i+1][1]);
			}
		}
		else{
			f_l[i][1]=m,f_r[i][1]=0;
		}
	}
	if(f_l[1][0]>0&&f_l[1][1]>0){
		puts("No");
		return 0;
	}
	puts("Yes");
	int left=0,right=0;
	for(int i=1;i<=n;i++){
		if(f_l[i][0]<=right&&right<=f_r[i][0]){
			left=c[i];
			printf("0 ");
		}
		else{
			right=c[i];
			printf("1 ");
		}
	}
	puts("");
	return 0;
}