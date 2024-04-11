#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;
typedef long long INT;
typedef pair <int, int> pii;
typedef vector <int> VI;

int main (){
#ifndef ONLINE_JUDGE
	freopen ("in.in", "r", stdin);
	freopen ("out.out", "w", stdout);
#endif
	
	int T, n, s, t;
	for(cin >> T; T--; ){
		cin >> n >> s >> t;
		int a=s-(s+t-n);
		int b=t-(s+t-n);
		printf("%lld\n",(long long)min(n, max(a, b)+1));
	}
	
	return 0;
}