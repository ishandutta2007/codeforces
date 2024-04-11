// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

bool arr[maxn][maxn];
ll n;

void build(ll x){
	REP(i,(n-x))
		arr[i][i+1]=arr[i+1][i]=1;
}

int main(){
	ll a,b;cin>>n>>a>>b;
	if((a!=1&&b!=1)||(a==1&&b==1&&(n==2||n==3))){
		cout<<"NO";
		return 0;
	}
	if(b==1){
		build(a);
	}
	else{
		build(b);
		REP(i,n){
			REP(j,n){
				if(i!=j)
					arr[i][j]=!arr[i][j];
			}
		}
	}
	cout<<"YES\n";
	REP(i,n){
		REP(j,n)
			cout<<arr[i][j];
		cout<<endl;
	}
}