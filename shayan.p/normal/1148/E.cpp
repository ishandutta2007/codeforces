// High above the clouds there is a rainbow...

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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

stack<int>st;
pii p[maxn];
int a[maxn];
vector<pair<pii,int> > ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].F;
	p[i].S=i;
    }
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    sort(p,p+n);
    sort(a,a+n);
    for(int i=0;i<n;i++){
	a[i]-=p[i].F;
	if(a[i]>=0){
	    st.push(i);
	}
	else{
	    while(sz(st)){
		int id=st.top();
		if(a[id]<=-a[i]){
		    ans.PB({{p[id].S,p[i].S},a[id]});
		    a[i]+=a[id];
		    a[id]=0;
		    st.pop();
		}
		else{
		    ans.PB({{p[id].S,p[i].S},-a[i]});
		    a[id]+=a[i];
		    a[i]=0;
		    break;
		}
	    }
	    if(a[i]!=0) return cout<<"NO\n",0;
	}
    }
    while(sz(st)){
	if(a[st.top()]!=0) return cout<<"NO\n",0;
	st.pop();
    }
    cout<<"YES\n"<<sz(ans)<<"\n";
    for(auto x:ans){
	cout<<x.F.F+1<<" "<<x.F.S+1<<" "<<x.S<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.