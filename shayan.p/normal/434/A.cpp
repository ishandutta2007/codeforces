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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
int a[maxn];
ll start[maxn];

ll solve(vector<int>&vec){
    if(vec.empty()) return 0;
    sort(vec.begin(),vec.end());
    int opt=vec[sz(vec)/2];
    ll ans=0;
    for(int x:vec)
	ans+=abs(opt-x);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    ll ans=0;
    for(int i=0;i<m;i++){
	cin>>a[i];
    }
    m=unique(a,a+m)-a;
    for(int i=1;i<m;i++){
	v[a[i]].PB(a[i-1]);
	v[a[i-1]].PB(a[i]);
	start[a[i]]+=abs(a[i-1]-a[i]);
	start[a[i-1]]+=abs(a[i-1]-a[i]);
	ans+=abs(a[i]-a[i-1]);
    }
    ll mn=0;
    for(int i=1;i<=n;i++){
	mn=min(mn,-start[i]+solve(v[i]));
    }
    ans+=mn;
    cout<<ans<<endl;
    return 0;
}