// Phoenix

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

const int maxn=5e5+10;

ll a[maxn],Not[maxn],n;

struct fenwick{
    ll fn[maxn];
    fenwick(){
	memset(fn,0,sizeof fn);
    }
    void add(int id,ll x){
	id+=3;
	while(id<maxn)
	    fn[id]+=x,id+=(id & -id);
    }
    ll ask(int id){
	ll ans=0;
	id+=3;
	while(id>0)
	    ans+=fn[id],id-=(id & -id);
	return ans;
    }
};fenwick fn[2];

void add(ll x){
    fn[0].add(x,1);
    fn[1].add(x,x);
}
void rem(ll x){
    fn[0].add(x,-1);
    fn[1].add(x,-x);
}
ll ask(ll x){
    return 1ll*x*(fn[0].ask(maxn-10)-fn[0].ask(x))+fn[1].ask(x);
}
void addnt(ll l,ll r){
    if(l>r) return;
    l=max(l,ll(0));
    r=min(r,ll(n));
    Not[l]++;Not[r+1]--;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
	cin>>a[i],add(a[i]);
    sort(a,a+n,greater<int>());
    ll sm=0;
    for(int i=0;i<n;i++){
	ll num=1ll*(i+1)*i+ask(i+1)-sm;
	addnt(max(ll(a[i]),num+1),n);
	sm+=a[i];
	rem(a[i]);
	num=1ll*(i+1)*i+ask(i+1)-sm;
	if(i+1<-num) addnt(0,a[i]);
	else addnt(0,min(ll(a[i]),-num-1));
    }
    ll X=0;
    vector<int>ans;
    for(int i=0;i<=n;i++){
	X+=Not[i];
	if(X==0 && (sm+i)%2==0)
	    ans.PB(i);
    }
    if(ans.empty()) cout<<-1;
    else for(ll x:ans) cout<<x<<" ";
    cout<<endl;
    return 0;
}