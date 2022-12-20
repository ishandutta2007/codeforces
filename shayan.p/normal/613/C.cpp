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

const ll maxn=30;

#pragma GCC Optimize("Ofast")

ll a[maxn];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void print(ll ch,ll cnt){
	REP(i,cnt)
		cout<<char('a'+ch);
}
void print(deque<ll>&d){
	REP(i,sz(d))
		cout<<char('a'+d[i]);
}
int main(){
	ll n;cin>>n;
	REP(i,n)
		cin>>a[i];
	ll cnt_odd=0,odd=0,g=a[0];
	REP(i,n){
		if(a[i]%2){
			cnt_odd++;
			odd=i;
		}
		g=gcd(g,a[i]);
	}
	if(cnt_odd==0){
		cout<<g<<endl;
		REP(i,g){
			if(i%2){
				REP(j,n)
					print(j,(a[j]/g));
			}
			else{
				REPD(j,n)
					print(j,(a[j]/g));
			}
		}
	}
	else if(cnt_odd==1){
		cout<<g<<endl;
		deque<ll>block;
		a[odd]-=g;
		REP(i,n){
			REP(j,(a[i]/(2*g))){
				block.PB(i);
				block.PF(i);
			}
		}
		block.PB(odd);
		REP(i,g)
			print(block);
	}
	else{
		cout<<0<<endl;
		REP(i,n)
			print(i,a[i]);
	}
}