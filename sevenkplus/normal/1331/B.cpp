#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int main() {
	int n;
	cin >> n;
	for (int i = 2; i < n; i ++)
	    if (n%i == 0) {
	        printf("%d%d\n",i,n/i);
	        return 0;
	    }
	return 0;
}