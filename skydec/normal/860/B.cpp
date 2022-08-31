#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=70025;
map<int,int>f[3];
int num[7][1000000];
int val[N][10][10];
int n;
int a[N];
int b[10];
void fucking(int x,int v){
	rep(l,1,9)rep(r,l,9){
		if(r-l+1<=6)num[r-l+1][val[x][l][r]]+=v;
		else f[r-l+1-7][val[x][l][r]]+=v;
	}
}
int fd(int x,int y){
	if(x<=6)return num[x][y];
	else return f[x-7][y];
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		int x=a[i];
		rep(j,1,9){
			b[j]=x%10;
			x/=10;
		}
		rep(j,1,9){
			val[i][j][j]=b[j];
			rep(k,j+1,9){
				val[i][j][k]=val[i][j][k-1]*10+b[k];
			}
		}
	}
	rep(i,1,n){
		fucking(i,1);
	}
	rep(i,1,n){
		fucking(i,-1);

		int x=a[i];
		rep(j,1,9){
			b[j]=x%10;
			x/=10;
		}
		bool ok=0;
		rep(len,1,9){
			if(ok)break;
			rep(l,1,10-len){
				int r=l+len-1;
				int w=val[i][l][r];
				//printf("_%d\n",w);
				if(fd(len,w)==0){
					per(k,r,l)printf("%d",b[k]);
					putchar('\n');
					ok=1;
					break;
				}
			}
		}
		fucking(i,1);
	}
	return 0;
}