#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		for(ri i=1;i<=6;++i)a[s[i]]=i;
		if(a['R']<a['r']||a['G']<a['g']||a['B']<a['b'])puts("NO");
		else puts("YES");
		
	}
	return 0;
}