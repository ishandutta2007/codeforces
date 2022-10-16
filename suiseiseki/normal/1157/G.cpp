#include <cstdio>
#include <cstring>
const int Maxn=200;
int n,m;
int a[Maxn+5][Maxn+5];
int b[Maxn+5][Maxn+5];
bool h[Maxn+5],l[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=1;j++){
			memset(h,0,sizeof h);
			memset(l,0,sizeof l);
			memcpy(b,a,sizeof a);
			if((h[1]=j)){
				for(int k=1;k<=m;k++){
					b[1][k]^=1;
				}
			}
			for(int k=1;k<=m;k++){
				if((k<m-i+1&&b[1][k])||(k>=m-i+1&&b[1][k]==0)){
					l[k]=1;
					for(int j=1;j<=n;j++){
						b[j][k]^=1;
					}
				}
			}
			bool flag=1;
			for(int k=2;flag&&k<=n;k++){
				h[k]=(b[k][1]^1);
				for(int l=2;flag&&l<=m;l++){
					flag=(b[k][1]==b[k][l]);
				}
			}
			if(flag){
				puts("YES");
				for(int i=1;i<=n;i++){
					printf("%d",h[i]);
				}
				puts("");
				for(int i=1;i<=m;i++){
					printf("%d",l[i]);
				}
				puts("");
				return 0;
			}
		}
	}
	for(int j=0;j<=1;j++){
		memset(h,0,sizeof h);
		memset(l,0,sizeof l);
		memcpy(b,a,sizeof a);
		if((h[1]=j)){
			for(int k=1;k<=m;k++){
				b[1][k]^=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(b[1][k]){
				l[k]=1;
				for(int j=1;j<=n;j++){
					b[j][k]^=1;
				}
			}
		}
		bool flag=1,has=0;
		for(int k=2;flag&&k<=n;k++){
			bool f=(b[k][1]==b[k][m]);
			if(!f){
				if(has){
					flag=0;
				}
				else{
					has=1;
					h[k]=b[k][1];
					bool rev=0;
					for(int l=2;flag&&l<m;l++){
						if(b[k][l]!=b[k][rev?m:1]){
							if(rev){
								flag=0;
							}
							else{
								rev=1;
							}
						}
					}
				}
			}
			else{
				h[k]=has^b[k][1];
				for(int j=2;flag&&j<=m;j++){
					if(b[k][1]!=b[k][j]){
						flag=0;
					}
				}
			}
		}
		if(flag){
			puts("YES");
			for(int i=1;i<=n;i++){
				printf("%d",h[i]);
			}
			puts("");
			for(int i=1;i<=m;i++){
				printf("%d",l[i]);
			}
			puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}