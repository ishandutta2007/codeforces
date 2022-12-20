// Faster!

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

int ans[maxn];
pair<pii,int>p[maxn];
pair<pii,pii>pp[maxn];
map<int,vector<int> >mp;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].F.F>>p[i].F.S;
	p[i].S=i;
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){
	cin>>pp[i].F.F>>pp[i].F.S>>pp[i].S.F;
	pp[i].S.S=i;
    }
    sort(p,p+n,[](pair<pii,int>a,pair<pii,int>b){return a.F.S<b.F.S;});
    sort(pp,pp+m,[](pair<pii,pii>a,pair<pii,pii>b){return a.F.S<b.F.S;});
    memset(ans,-1,sizeof ans);
    int pt=0;
    for(int i=0;i<m;i++){
	while(pt<n && p[pt].F.S<=pp[i].F.S) mp[p[pt].F.F].PB(p[pt].S),pt++;
	for(auto it=mp.lower_bound(pp[i].F.F);it!=mp.end() && pp[i].S.F>0 ; ++it,mp.erase(prev(it))){
	    vector<int>&vec=it->S;
	    while(sz(vec) && pp[i].S.F>0){
		ans[vec.back()]=pp[i].S.S;
		pp[i].S.F--;
		vec.pop_back();
	    }
	    if(sz(vec)>0) break;
	}
    }
    for(int i=0;i<n;i++){
	if(ans[i]==-1)
	    return cout<<"NO\n",0;
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
	cout<<ans[i]+1<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.