#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))

ll gcd(ll a, ll b){
	while(a%b != 0){
		ll c = a%b;
		a = b;
		b = c;
	}
	return b;
}

//max,min
pair<ll,ll> calc(ll n, ll k, ll a, ll b){
	ll mini = LINF;
	ll maxi = 1;
	ll m = 0;
	while((n+1) * k + abs(a) + abs(b) >= m * k + a + b){
		if(m*k+a+b>=1){
			ll memo = gcd(n*k,m*k+a+b);
			chmax(maxi,memo);
			chmin(mini,memo);
		}

		m++;
	}
	return pair<ll,ll>(n*k/mini,n*k/maxi);
}


int main(void){
	ll n,k,a,b;
	cin>>n>>k;
	cin>>a>>b;
	pair<ll,ll> memo;
	ll mini = LINF;
	ll maxi = 0;
	memo = calc(n,k,a,b);
	chmax(maxi,memo.first);
	chmin(mini,memo.second);
	memo = calc(n,k,-1*a,-1*b);
	chmax(maxi,memo.first);
	chmin(mini,memo.second);
	memo = calc(n,k,a,-1*b);
	chmax(maxi,memo.first);
	chmin(mini,memo.second);
	memo = calc(n,k,-1*a,b);
	chmax(maxi,memo.first);
	chmin(mini,memo.second);
	cout<<mini<<" "<<maxi<<endl;
	return 0;
}