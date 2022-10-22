#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int T,n,k,a[o];set<int> s;
inline void slv(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),s.insert(a[i]);
	for(int i=1;i<=n;++i) if(s.find(a[i]+k)!=s.end()){printf("YES\n");return;}
	printf("NO\n");
}
int main(){for(scanf("%d",&T);T--;s.clear()) slv();return 0;}