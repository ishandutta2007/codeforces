// Mikaeel_noob_e_sag_e

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int> v[maxn];
int a[maxn],pr[maxn];
map<int,set<pii> >mp;
set<int>st;

pii far(int u,int par=-1){
    pii ans={0,u};
    st.erase(u);
    for(int y:v[u]){
	if(y!=par){
	    pii p=far(y,u);
	    p.F++;
	    ans=max(ans,p);
	}
    }
    return ans;
}

void Add(int a,int b,int x){
    while(x>1){
	int p=pr[x];
	mp[p].insert({a,b});
	while(x%p==0) x/=p;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    for(int i=2;i<maxn;i++){
	if(pr[i]==0){
	    for(int j=i;j<maxn;j+=i)
		pr[j]=i;
	}
    }
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]!=1) ans=1;
    }
    for(int i=1;i<n;i++){
	int x,y;cin>>x>>y;
	Add(x,y,gcd(a[x],a[y]));
    }
    for(auto &x:mp){
	st.clear();
	for(pii e:x.S){
	    v[e.F].clear();
	    v[e.S].clear();
	    st.insert(e.F);
	    st.insert(e.S);
	}
	for(pii e:x.S){
	    v[e.F].PB(e.S);
	    v[e.S].PB(e.F);
	}
	while(sz(st)){
	    int u=*st.begin();
	    u=far(u).S;
	    ans=max(ans,far(u).F+1);
	}
    }
    cout<<ans<<endl;
    return 0;
}