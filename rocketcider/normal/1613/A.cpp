#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
inline int lg(ll k){return floor(log10(k));}
int t_case;
ll a[maxn],m,n,x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld%lld",&n,&x,&m,&y);
		if(lg(n)+x==lg(m)+y){
			while(lg(n)!=lg(m)){
				if(lg(n)<lg(m)){
					if(x)n*=10,--x;
					else break;
				}
				else{
					if(y)m*=10,--y;
					else break;
				}
			}
			if(n==m)puts("=");
			else puts(n<m?"<":">");
		}
		else puts(lg(n)+x<lg(m)+y?"<":">");
	}
	return 0;
}