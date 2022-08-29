#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=3e3+5,P=1e9+7;
vector<int>a[N],b;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}
	rep(i,m)sort(a[i].begin(),a[i].end());
	ll ans=1e18,ss;
	for(int i=n;~i;--i){
		ss=0;
		int cur=a[1].size();b.clear();
		for(int j=2;j<=m;++j){
			int p;
			if(a[j].size()>i){
				p=a[j].size()-i;
				cur+=p;
				for(int k=0;k<p;++k)ss+=a[j][k];
			}else p=0;
				for(int k=p;k<a[j].size();++k)
					b.push_back(a[j][k]);
		}
		//printf("%d %d\n",i,cur);
		if(cur+b.size()<=i)continue;
		if(cur<=i){
			sort(b.begin(),b.end());
			int p=i+1-cur;
			for(int k=0;k<p;++k)ss+=b[k];
		}
		ans=min(ans,ss);
	}
	printf("%lld\n",ans);
}