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

int main(){
    vector<ll>v;
    ll n;cin>>n;
    string s;cin>>s;
    char bf=s[0];
    ll c=0;
    REP(i,sz(s)){
	if(s[i]==bf){
	    c++;
	}
	else{
	    v.PB(c);
	    c=1;
	    bf=s[i];
	}
    }
    v.PB(c);

    ll b1=0,b2=0;
    REP(i,sz(v)){
	b1+=(v[i]>2);
	b2+=(v[i]>1);
    }

    if(b1>0){
	cout<<sz(v)+2;
	return 0;
    }
    if(b2>1){
	cout<<sz(v)+2;
	return 0;
    }
    if(b2==1){
	cout<<sz(v)+1;
	return 0;
    }
    cout<<sz(v);
}