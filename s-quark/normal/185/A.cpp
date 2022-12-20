#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int P = 1000000007; 

int main()
{
	#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ll n;
	int s;
	int i;
	cin>>n;
	s = 1;
	for(i = 61; i >= 0; i--){
		s = (ll)s*s%P;
		if(1LL<<i&n)
			s = s*2%P;
	}
	n = (ll)s*(s+1)/2%P;
	cout<<n<<endl;
	return 0;
}