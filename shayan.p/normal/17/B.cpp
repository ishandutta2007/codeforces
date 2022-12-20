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

const int maxn=1e5+10,inf=2e9;

pii p[maxn];
int mn[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	p[i]={x,i};
    }
    sort(p,p+n,greater<pii>());
    fill(mn,mn+n,inf);
    mn[p[0].S]=0;
    int m;cin>>m;
    while(m--){
	int a,b,c;cin>>a>>b>>c; --b;
	mn[b]=min(mn[b],c);
    }
    int ans=0;
    for(int i=0;i<n;i++){
	if(mn[i]==inf) return cout<<-1<<endl,0;
	ans+=mn[i];
    }
    cout<<ans<<endl;
    return 0;
}