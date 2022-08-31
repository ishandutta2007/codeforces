#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1005;
int a[N][5];
int b[N][5];
int n;
int q[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		rep(j,0,4)scanf("%d",&a[i][j]);
	}
	rep(i,1,n){
		rep(j,1,n)rep(k,0,4)b[j][k]=a[j][k]-a[i][k];
		bool flg=0;
		rep(j,1,n)if(j!=i){
			int c=0;
			bool dd=0;
			rep(d,1,n)if(j!=d&&d!=i){
				++c;
				if(c>35)break;
				int v=0;
				rep(k,0,4)v+=b[j][k]*b[d][k];
				if(v>0){
					dd=1;
					break;
				}
			}
			if(dd){
				flg=1;
				break;
			}
		}
		if(!flg){
			q[++q[0]]=i;
		}
	}
	printf("%d\n",q[0]);
	rep(i,1,q[0])printf("%d\n",q[i]);
	return 0;
}