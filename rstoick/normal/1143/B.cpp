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
#define INF (int)(1e9+10)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))

ll seki(ll n){
	ll ret = 1;
	if(n==0) return 0;
	while(n>0){
		ret *= n%10;
		n /= 10;
	}
	return ret;
}

int main(void){
	ll n;
	ll ans = 0;
	cin>>n;
	ll d = 10;
	while(n>0){
		chmax(ans,seki(n));
		if(n%d - n%(d/10) != 9){
			n -= (n%d - n%(d/10) + d/10);
		}
		d *= 10;
	}
	cout<<ans<<endl;
}