#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=n;i;--i)printf("%d ",i);
		printf("\n");
		for(ri i=2;i<=n;++i){
			for(ri j=n;j;--j){
				if(j==i)printf("%d %d ",j-1,j),--j;
				else printf("%d ",j);
			}
			printf("\n");
		}
	}
	return 0;
}