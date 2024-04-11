#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <memory.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

const int MN = 1000111;

int main() {
    cin.sync_with_stdio(false); cin.tie(0);
		int n;
		vector<int> a(1000111);
		while (cin >> n) {
			for(int i = 1; i <= n; ++i)
				cin >> a[i];
			vector<int> bad(1000111);
			int q;
			cin >> q;
			while (q--) { int u; cin >> u; bad[u] = true; }

			stack<int> st;
			for (int i = n; i >= 1; --i) {
				if (bad[i]) a[i] = -a[i];
				else if (!st.empty() && st.top() == a[i]) {
					a[i] = +a[i];
				}
				else {
					a[i] = -a[i];
				}

				if (a[i] > 0) st.pop();
				else st.push(-a[i]);
			}
			if (st.empty()) {
				puts("YES");
				for(int i = 1; i <= n; ++i)  printf("%d ", a[i]);
				puts("");
			}
			else puts("NO");
			break;
		}
    return 0;
}