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

stack<ll>st;
bool mark[maxn];

int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    REP(i,sz(s)){
	if(s[i]=='('){
	    st.push(i);
	}
	else if(k>0){
	    k-=2;
	    mark[i]=1;
	    mark[st.top()]=1;
	    st.pop();
	}	    
    }
    REP(i,sz(s)){
	if(mark[i]){
	    cout<<s[i];
	}
    }
}