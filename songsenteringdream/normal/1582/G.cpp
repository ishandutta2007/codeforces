#include<cstdio>
#include<vector>
#include<utility>
#include<iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int o=1e6+10;
int n,a[o],w[o],pri[o],cnt,St[o],tp;long long ans;char b[o];
vector<int> vec[o];vector<pair<int,int> > st[o];
inline int calc(int p,int val){int res=0;for(;val%pri[p]==0;val/=pri[p]) ++res;return res;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("%s",b+1);
	for(int i=2;i<o;++i) if(!w[i]) for(int j=pri[++cnt]=i;j<o;j+=i) ++w[j];
	for(int i=1;i<o;++i) vec[i].reserve(w[i]);
	for(int i=1;i<=cnt;++i) for(int j=pri[i];j<o;j+=pri[i]) vec[j].push_back(i);
	for(int i=1;i<=n;++i,ans+=tp)
		if(b[i]=='*'){
			St[++tp]=i;
			for(int j=0;j<w[a[i]];++j) st[vec[a[i]][j]].push_back(make_pair(i,calc(vec[a[i]][j],a[i])));
		}
		else{
			if(a[i]==1) St[++tp]=i;
			for(int j=0,p,v;j<w[a[i]];++j) for(v=calc(p=vec[a[i]][j],a[i]);1;st[p].pop_back())
				if(st[p].empty()){tp=0;break;}
				else if(st[p].back().second<v) for(v-=st[p].back().second;tp&&St[tp]>=st[p].back().first;--tp);
				else{for(st[p].back().second-=v;tp&&St[tp]>st[p].back().first;--tp);break;}
		}
	printf("%lld",ans);
	return 0;
}