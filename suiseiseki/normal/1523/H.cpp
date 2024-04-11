#include <cstdio>
#include <algorithm>
const int Maxn=20000;
const int Maxd=17;
const int Maxk=30;
int n,q;
int nxt[Maxd+1][Maxk+1][Maxn+1];
int f_max[Maxk+1][Maxd+1][Maxn+1];
int a[Maxn+1];
int log_2[Maxn+1];
void init(){
	log_2[0]=-1;
	for(int i=1;i<=Maxn;i++){
		log_2[i]=log_2[i>>1]+1;
	}
}
int query_max(int k,int l,int r){
	int d=log_2[r-l+1];
	return std::max(f_max[k][d][l],f_max[k][d][r-(1<<d)+1]);
}
int ans[Maxn+1];
int pos_r[Maxn+1][Maxk+1];
struct Question{
	int l,r,k;
}qu[Maxn+1];
int main(){
	init();
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=Maxk;j++){
			nxt[0][j][i]=std::min(i+a[i]+j,n);
		}
	}
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=Maxk;k++){
				f_max[k][0][j]=nxt[i-1][k][j];
			}
		}
		for(int k=0;k<=Maxk;k++){
			for(int j=1;(1<<j)<=n;j++){
				for(int l=1;l+(1<<j)-1<=n;l++){
					f_max[k][j][l]=std::max(f_max[k][j-1][l],f_max[k][j-1][l+(1<<(j-1))]);
				}
			}
		}
		for(int k_1=0;k_1<=Maxk;k_1++){
			for(int k_2=0;k_1+k_2<=Maxk;k_2++){
				for(int j=1;j<=n;j++){
					nxt[i][k_1+k_2][j]=std::max(nxt[i][k_1+k_2][j],query_max(k_2,j,nxt[i-1][k_1][j]));
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&qu[i].l,&qu[i].r,&qu[i].k);
		for(int j=0;j<=qu[i].k;j++){
			pos_r[i][j]=qu[i].l;
		}
		if(qu[i].l==qu[i].r){
			ans[i]=-1;
			continue;
		}
	}
	for(int i=17;i>=0;i--){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=Maxk;k++){
				f_max[k][0][j]=nxt[i][k][j];
			}
		}
		for(int k=0;k<=Maxk;k++){
			for(int j=1;(1<<j)<=n;j++){
				for(int l=1;l+(1<<j)-1<=n;l++){
					f_max[k][j][l]=std::max(f_max[k][j-1][l],f_max[k][j-1][l+(1<<(j-1))]);
				}
			}
		}
		for(int j=1;j<=q;j++){
			if(ans[j]==-1){
				continue;
			}
			static int np_r[Maxk+5];
			for(int k=0;k<=qu[j].k;k++){
				np_r[k]=0;
			}
			for(int k_1=0;k_1<=qu[j].k;k_1++){
				for(int k_2=0;k_1+k_2<=qu[j].k;k_2++){
					np_r[k_1+k_2]=std::max(np_r[k_1+k_2],query_max(k_2,qu[j].l,pos_r[j][k_1]));
				}
			}
			if(np_r[qu[j].k]<qu[j].r){
				ans[j]+=(1<<i);
				for(int k=0;k<=qu[j].k;k++){
					pos_r[j][k]=np_r[k];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]+1);
	}
	return 0;
}