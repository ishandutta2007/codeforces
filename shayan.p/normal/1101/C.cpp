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

pair<pii,int> p[maxn];
int ans[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie();
    
    int t;cin>>t;
    while(t--){
	int n;cin>>n;
	for(int i=0;i<n;i++)
	    cin>>p[i].F.F>>p[i].F.S,p[i].S=i;
	sort(p,p+n);
	int lst=p[0].F.F;
	int id=0;
	while(id<n && lst>=p[id].F.F)
	    lst=max(lst,p[id].F.S),id++;
	if(id==n){
	    cout<<-1<<"\n";
	    continue;
	}
	for(int i=0;i<id;i++)
	    ans[p[i].S]=t+100;
	for(int i=0;i<n;i++)
	    cout<<(ans[i]==t+100 ? 1 : 2)<<" ";
	cout<<"\n";
    }
    return 0;
}