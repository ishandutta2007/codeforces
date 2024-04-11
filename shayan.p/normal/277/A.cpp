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

const int maxn=300,mod=1e9+7;
const ll inf=1e18;

int arr[maxn],par[maxn];
set<int>st;

int Find(int u){
    return par[u]<0?u:par[u]=Find(par[u]);
}
bool Merge(int a,int b){
    if((a=Find(a))==(b=Find(b))) return 0;
    par[a]+=par[b];
    par[b]=a;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    memset(par,-1,sizeof par);
    int n,m;cin>>n>>m;
    bool any=0;
    for(int j=0;j<n;j++){
	int t;cin>>t;
	any|=t>0;
	for(int i=0;i<t;i++)
	    cin>>arr[i];
	for(int i=0;i<t;i++)
	    Merge(j,101+arr[i]);
    }
    for(int i=0;i<n;i++){
	st.insert(Find(i));
    }
    cout<<sz(st)-any<<endl;
}