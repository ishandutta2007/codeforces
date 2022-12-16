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
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll n;
vector<bool>v1,v2;

bool ask(ll a,ll b,ll c,ll d){
    if(a<=0 || b<=0 || c<=0 || d<=0 || a>n || b>n || c>n || d>n || a>c || b>d)return 0;
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    string s;cin>>s;
    return (s=="YES");
}

void dfs1(ll x,ll y){
    if((x+y)==(n+1))return;
    if(ask(x,y+1,n,n)){
	v1.PB(1);
	dfs1(x,y+1);
    }
    else{
	v1.PB(0);
	dfs1(x+1,y);
    }
}

void dfs2(ll x,ll y){
    if((x+y)==(n+1))return;
    if(ask(1,1,x-1,y)){
	v2.PB(0);
	dfs2(x-1,y);
    }
    else{
	v2.PB(1);
	dfs2(x,y-1);
    }
}

int main(){
    cin>>n;
    dfs1(1,1);
    dfs2(n,n);
    cout<<"! ";
    REP(i,sz(v1)){
	cout<<(v1[i]?'R':'D');
    }
    REPD(i,sz(v2)){
	cout<<(v2[i]?'R':'D');
    }
}