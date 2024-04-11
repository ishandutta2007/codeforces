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
const ll maxn=110;
const ll mod=1e9+7;

ll a[maxn],b[maxn],A,B;

int main(){
    ll n,m;cin>>n>>m;
    FOR(i,1,n){
	cin>>a[i];
	A^=a[i];
    }
    FOR(i,1,m){
	cin>>b[i];
	B^=b[i];
    }
    if(A!=B){
	cout<<"NO";
	return 0;
    }
    cout<<"YES\n";
    FOR(i,1,n){
	FOR(j,1,m){
	    if(i<n && j<m)cout<<0<<" ";
	    else if(i==n && j<m) cout<<b[j]<<" ";
	    else if(j==m && i<n) cout<<a[i]<<" ";
	    else cout<<(B^a[n]^b[m])<<" ";
	}
	cout<<endl;
    }
}