#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int o=2e5+10;
int T,n,a[o],s[o],b[o],cnt,c[o],d[o],t;vector<int> v[o];set<int> S;set<int>::iterator iter;
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) v[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),v[a[i]].push_back(i);
		for(int i=1;i<=n;++i) if(s[i]=v[i].size()) S.insert(i);
		for(int i=0;i<n;++i){
			for(cnt=t=0,iter=S.begin();iter!=S.end();++iter) c[++cnt]=*iter;
			for(int j=1;j<=cnt;++j) if(s[c[j]]==i) S.erase(c[j]);else d[++t]=v[c[j]][i];
			for(int j=1;j<=t;++j) b[d[j]]=a[d[j%t+1]];
		}
		for(int i=1;i<=n;++i) printf("%d ",b[i]); 
	}
	return 0;
}