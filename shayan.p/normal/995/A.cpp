// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=53;
const ll mod=1e9+7;

pll pos[maxn];
ll a[2][maxn];
ll n,k;
vector< pair<ll,pll> >ans;

void SWAP(ll x1,ll y1,ll x2,ll y2){
    if(a[x1][y1]==0&&a[x2][y2]==0)return;
    if(a[x2][y2]==0){
	swap(x1,x2);
	swap(y1,y2);
    }
    ans.PB({a[x2][y2],{x1+2,y1+1}});
    a[x1][y1]=a[x2][y2];
    a[x2][y2]=0;
}

void DEL(ll x,ll y){
    ans.PB({a[x][y],{(x==0?1:4),y+1}});
    a[x][y]=0;
}

bool REMOVE(){
    bool is=0;
    REP(i,n){
	if(a[0][i]!=0 && pos[a[0][i]].F==0 && pos[a[0][i]].S==i){
	    DEL(0,i);
	    is=1;
	}
    }
    REP(i,n){
	if(a[1][i]!=0 && pos[a[1][i]].F==1 && pos[a[1][i]].S==i ){
	    DEL(1,i);
	    is=1;
	}
    }
    return is;
}

bool NORMAL(){
    pll emp=MP(-1,-1);
    REP(i,n){
	if(a[0][i]==0)
	    emp=MP(0,i);
	if(a[1][i]==0)
	    emp=MP(1,i);
    }
    if(emp.F==-1)return 0;
    while(emp.F>0){
	SWAP(emp.F,emp.S,emp.F-1,emp.S);
	emp.F--;
    }
    while(emp.S>0){
	SWAP(emp.F,emp.S,emp.F,emp.S-1);
	emp.S--;
    }
    return 1;
}

void MOVE(){
    REP(i,n-1){
	SWAP(0,i,0,i+1);
	REMOVE();
    }
    SWAP(0,n-1,1,n-1);
    REMOVE();
    REPD(i,n-1){
	SWAP(1,i+1,1,i);
	REMOVE();
    }
    SWAP(1,0,0,0);
    REMOVE();
}

int main(){
    cin>>n>>k;
    REP(i,n){
	ll x;cin>>x;
	if(x!=0)
	    pos[x]=MP(0,i);
    }
    REP(i,n){
	cin>>a[0][i];
    }
    REP(i,n){
	cin>>a[1][i];
    }
    REP(i,n){
	ll x;cin>>x;
	if(x!=0)
	    pos[x]=MP(1,i);
    }
    bool ys = !REMOVE();
    ys&= !NORMAL();
    if(ys){
	cout<<-1;
	return 0;
    }
    
    REP(i,2*n+10){
	MOVE();
    }

    cout<<sz(ans)<<endl;
    REP(i,sz(ans)){
	cout<<ans[i].F<<" "<<ans[i].S.F<<" "<<ans[i].S.S<<endl;
    }
}