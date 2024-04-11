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
int n,m,ans1[maxn],ans2[maxn];

pii find_edge(){
    for(int i=1;i<=n;i++){
	if(sz(v[i])<n-1){
	    sort(v[i].begin(),v[i].end());
	    for(int j=0;j<sz(v[i]);j++){
		if(v[i][j]!=j+1+(j>=(i-1)))
		    return {i,j+1+(j>=(i-1))};
	    }
	    return {i,sz(v[i])+1+(sz(v[i])>=(i-1))};
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
	v[b].PB(a);
    }
    if((2ll*m)==(1ll*n*(n-1))) return cout<<"NO\n",0;
    pii p=find_edge();
    ans1[p.F]=ans2[p.F]=ans2[p.S]=1;
    ans1[p.S]=2;
    int C=2;
    for(int i=1;i<=n;i++){
	if(i!=p.F && i!=p.S){
	    ans1[i]=ans2[i]=++C;
	}
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
	cout<<ans1[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
	cout<<ans2[i]<<" ";
    cout<<endl;
    return 0;
}