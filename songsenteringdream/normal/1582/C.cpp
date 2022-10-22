#include<cstdio>
using namespace std;
inline int Min(int a,int b){return a<b?a:b;}
const int o=2e5+10;
int T,n,ans;char s[o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans>n?-1:ans)){
		scanf("%d%s",&n,s+1);ans=n+1;
		for(int c='a',l,r,res;c<='z';++c,ans=Min(ans,res))
			for(l=1,r=n,res=0;l<r;)
				if(s[l]^s[r]) if(s[l]==c) ++res,++l;else if(s[r]==c) ++res,--r;else res=l=n+1;
				else ++l,--r;
	}
	return 0;
}