#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
const int o=5e4+10;
int T,n,m;vector<pair<int,long long> > a,b;
vector<pair<int,long long> > calc(){
	vector<pair<int,long long> > res;
	long long s=0;
	for(int i=1,x,j;i<=n;++i){
		scanf("%d",&x);
		for(j=1;x%m==0;j*=m) x/=m;
		if(!res.empty()&&res.back().first==x) res[res.size()-1].second+=j;
		else res.push_back(make_pair(x,j));
	}
	return res;
}
int main(){
	for(scanf("%d",&T);T--;printf(a==b?"Yes\n":"No\n")){
		scanf("%d%d",&n,&m);
		a=calc();scanf("%d",&n);b=calc();
	}
	return 0;
}