#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

const int maxn = 4000333;

int n, A, B;


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> A >> B >> n;
	while (n--) {
		int l, t, m;
		scanf("%d%d%d", &l, &t, &m);

		long long fi = A + (l - 1) * 1ll * B;

		int le = l - 1;
		int ri = maxn - 1;
		while (le < ri) {
			int mid = (le + ri + 1) / 2;
			
			if (A + (mid - 1) * 1ll * B > t) {
				ri = mid - 1;
				continue;
			}

			int len = mid - l + 1;

			double g = fi * 1. * len + len * 1. * (len - 1) / 2 * B;

			long long sum = fi * len + len * 1ll * (len - 1) / 2 * B;

			if (g > 2. * t * m || sum > t * 1ll * m) {
				ri = mid - 1;
				continue;
			}
			le = mid;
		}
		if (le == l - 1) le = -1;
		printf("%d\n", le);


	}
	return 0;
}