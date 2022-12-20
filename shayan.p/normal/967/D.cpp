// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=3e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

pll c[maxn];
vector<ll>vec1,vec2;
ll n,x1,x2;
ll k1,k2;

bool pos(){
	ll pt=0;k1=1;k2=1;
	bool ys1=0,ys2=0;
	while(pt<n){
		if((k1*c[pt].F)>=x1){
			ys1=1;
			break;
		}
		k1++;
		pt++;
	}
	pt++;
	while(pt<n){
		if((k2*c[pt].F)>=x2){
			ys2=1;
			break;
		}
		k2++;
		pt++;
	}
	return (ys1&&ys2);
}

void print(){
	cout<<"Yes\n";
	cout<<k1<<" "<<k2<<endl;
	REP(i,k1)
		cout<<c[i].S<<" ";
	cout<<endl;
	REP(i,k2)
		cout<<c[i+k1].S<<" ";
	exit(0);
}
void print_rev(){
	cout<<"Yes\n";
	cout<<k2<<" "<<k1<<endl;
	REP(i,k2)
		cout<<c[i+k1].S<<" ";
	cout<<endl;
	REP(i,k1)
		cout<<c[i].S<<" ";
	exit(0);
}

int main(){
	cin>>n>>x1>>x2;
	REP(i,n){
		cin>>c[i].F;
		c[i].S=i+1;
	}
	sort(c,c+n,greater<pll>());
	if(pos())
		print();
	swap(x1,x2);
	if(pos())
		print_rev();
	cout<<"No";
}