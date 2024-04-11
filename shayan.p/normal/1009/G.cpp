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
const ll maxn=1e5+10;
const ll mod=1e9+7;

ll ch[7],msk[maxn],OR[100];
string ans;

void add(ll u,ll x){
    REP(i,(1<<6)){
	OR[i]+=((u&i)>0)*x;
    }
}

bool check(){
    bool bans=1;
    REP(i,(1<<6)){
	ll num=0;
	REP(j,6){
	    if(bit(i,j))
		num+=ch[j];
	}
	bans&=(num<=OR[i]);
    }
    return bans;
}

int main(){
    string s;cin>>s;
    ll n=sz(s);
    REP(i,n){
	ch[s[i]-'a']++;
    }
    ll m;cin>>m;
    fill(msk,msk+maxn,63);
    REP(i,m){
	ll pos;
	cin>>pos>>s;
	msk[pos-1]=0;
	REP(j,sz(s)){
	    msk[pos-1]|=(1<<(s[j]-'a'));
	}
    }
    REP(i,n){
	add(msk[i],1);
    }
    REP(i,n){
	add(msk[i],-1);
	REP(j,6){
	    if(bit(msk[i],j)){
		ch[j]--;
		if(check()){
		    ans+=char(j+'a');
		    break;
		}
		ch[j]++;
	    }
	}
    }
    if(sz(ans)<n)
	cout<<"Impossible";
    else
	cout<<ans;
}