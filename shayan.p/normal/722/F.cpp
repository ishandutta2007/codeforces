// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=1e5+10,maxk=42,mod=1e9+7;
const ll inf=1e18;

vector< pair<int,pii> >v[maxn];// pos mod rem
vector<int>dv[maxk];
pii MD[maxk];// pos rem

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=2;i<maxk;i++){
	for(int j=i;j<maxk;j+=i)
	    dv[j].PB(i);
    }
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
	int md;cin>>md;
	for(int j=0;j<md;j++){
	    int x;cin>>x;
	    v[--x].PB({i,{md,j}});
	}
    }
    for(int i=0;i<m;i++){
	int ans=0,l=-1;
	memset(MD,-1,sizeof MD);// pair?
	for(int r=0;r<sz(v[i]);r++){
	    int ps=v[i][r].F,md=v[i][r].S.F,rm=v[i][r].S.S;
	    if(r!=0 && v[i][r-1].F+1!=ps) l=r-1;
	    for(int x:dv[md]){
		if(MD[x].F!=-1 && MD[x].S!=rm%x){
		    while(l<MD[x].F)
			++l;
		}
		MD[x]={r,rm%x};
	    }
	    ans=max(ans,r-l);
	}
	cout<<ans<<"\n";
    }
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.