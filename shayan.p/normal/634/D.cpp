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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

ll d,n;
pll p[maxn];
int sp[20][maxn],m;

int ask(int l,int r){// []
    int ln=31-__builtin_clz(r-l+1);
    int id1=sp[ln][l],id2=sp[ln][r-(1<<ln)+1];
    return p[id1].S<p[id2].S?id1:id2;
}

ll solve(int l,int r,ll lm){
    if((n-(p[r].F-p[l].F))>=lm) return 0;
    if(r-l==1){
	return p[r].S*max(ll(0),lm-(n-(p[r].F-p[l].F)));
    }
    if(lm!=0 && ask(l+1,r)==r) return solve(l,r,0)+(lm-max(ll(0),(n-p[r].F+p[l].F)))*p[r].S;
    int mid=ask(l+1,r-1);
    if((lm+p[r].F-p[mid].F)<=n) return solve(l,mid,lm+p[r].F-p[mid].F);
    return solve(l,mid,n)+solve(mid,r,lm);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>d>>n>>m;
    for(int i=1;i<=m;i++)
	cin>>p[i].F>>p[i].S;
    p[m+1].F=d;
    sort(p,p+m+2);
    m+=2;
    for(int i=0;i<m;i++){
	sp[0][i]=i;	
    }
    for(int i=0;i<m-1;i++){
	if(p[i+1].F-p[i].F>n){
	    return cout<<-1<<endl,0;
	}
    }
    if(n>=d){
	return cout<<0<<endl,0;
    }
    for(int i=1;i<20;i++){
	for(int j=0;j<m;j++){
	    int id1=sp[i-1][j],id2=sp[i-1][min(m-1,j+(1<<(i-1)))];
	    sp[i][j]=(p[id1].S<p[id2].S?id1:id2);
	}
    }
    ll ans=solve(0,m-1,0);
    if(ans==inf) ans=-1;
    cout<<ans<<endl;
    return 0;
}