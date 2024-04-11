#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define f first
#define s second
#define ll long long
using namespace std;
ll n,x[3000005],le,ri,idx1[1000000],idx2[1000000],jlh;
map<ll,pair<ll,ll> > m;
int main(){
	scanf("%lld",&n);
	rep(i,n)scanf("%lld",&x[i]);
	rep(i,n){
		m[x[i]].f++;
		if(m[x[i]].f==2){
			jlh++, idx1[jlh]=idx2[jlh-1]+1, idx2[jlh]=i;
			m.clear();
		}else m[x[i]].s=i;
	}idx2[jlh]=n;
	if(!jlh){
		cout<<-1<<endl;
		return 0;
	}
	cout<<jlh<<endl;
	rep(i,jlh)printf("%lld %lld\n",idx1[i],idx2[i]);
	return 0;
}