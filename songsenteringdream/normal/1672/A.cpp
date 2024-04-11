#include<cstdio>
using namespace std;
const int o=1e6;
int T,n,a,sg[o],vis[o],ans;
int main(){
	for(int i=2;i<51;++i){
		for(int j=1;j<i;++j) vis[sg[j]^sg[i-j]]=i;
		for(sg[i]=0;vis[sg[i]]==i;++sg[i]);
	}
	for(scanf("%d",&T);T--;printf(ans?"errorgorn\n":"maomao90\n"),ans=0)
		for(scanf("%d",&n);n--;ans^=sg[a]) scanf("%d",&a);
	return 0;
}