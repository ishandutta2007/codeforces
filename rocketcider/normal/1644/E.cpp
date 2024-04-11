#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&m,s+1);
		n=strlen(s+1);
		int pd=0,pr=0,x=1,y=1;
		for(ri i=1;i<=n;++i){
			if(s[i]=='D'){
				if(!pr)pr=x;
				++y;
			}
			if(s[i]=='R'){
				if(!pd)pd=y;
				++x;
			}
		}
		if(!pd||!pr)printf("%d\n",m);
		else printf("%lld\n",1+n+1ll*(m-x)*(y-pd+1)+1ll*(m-y)*(x-pr+1)+1ll*(m-x)*(m-y));
		clear(s,n);
	}
	return 0;
}