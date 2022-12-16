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
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

bool is[3];

int main(){
	string s;cin>>s;
	FOR(i,2,sz(s)-1){
		is[0]=is[1]=is[2]=0;
		REP(j,3){
			if(s[i-j]!='.') is[s[i-j]-'A']=1;
		}
		if(is[0]&&is[1]&&is[2]){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}