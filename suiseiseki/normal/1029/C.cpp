#include <cstdio>
#include <set>
using namespace std;
multiset<int> l,r;
int x[300005],y[300005];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		l.insert(x[i]);
		r.insert(y[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		l.erase(l.find(x[i]));
		r.erase(r.find(y[i]));
		ans=mx(ans,*r.begin()-(*--l.end()));
		l.insert(x[i]);
		r.insert(y[i]);
	}
	printf("%d\n",ans);
	return 0;
}