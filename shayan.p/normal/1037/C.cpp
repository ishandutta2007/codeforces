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

string s1,s2;

int main(){
    ll n,ans=0;cin>>n;
    cin>>s1>>s2;
    REP(i,n){
	if(s1[i]!=s2[i])
	    ans++;
    }
    REP(i,n-1){
	if(s1[i]!=s2[i] && s1[i+1]!=s2[i+1] && s1[i]!=s1[i+1]){
	    ans--;
	    i++;
	}
    }
    cout<<ans;
}