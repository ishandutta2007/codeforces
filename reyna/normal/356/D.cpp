//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int S = 300;
const int N = 70009;
int ed = 0;
bitset<N> b[S];
int num[S];
pair<int,int> a[N];
int fs[N],mark[N];
vector<int> ans[N];
int is[N];
int in[N];
int choose[N];
void call(int s,int v) {
	if(!s || v < 0) return;
	v = fs[s];
	choose[a[v].second] = 1;
	s -= a[v].first;
	call(s,v-1);
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,s; cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a,a + n);
	reverse(a,a + n);
	b[ed++].set(a[0].first);
	fs[a[0].first] = 0;
	mark[a[0].first] = 1;
	for (int i = 1; i < n; ++i) {
		b[ed] = b[ed - 1] | (b[ed - 1] << a[i].first);
		num[ed] = num[ed - 1] + 1;
		ed++;
		if (ed % S == 0 || i == n-1) {
			for (int j = 0; j <= s; ++j) {
				if (!mark[j] && b[ed - 1][j]) {
					for (int k = 0; k < ed; ++k) {
						if (b[k][j]) {
							fs[j] = num[k];
							break;
						}
					}
					mark[j] = 1;
				}
			}
			b[0] = b[ed - 1];
			num[0] = num[ed - 1];
			ed = 1;	
		}
	}
	if (!b[ed - 1][s]) {
		cout << -1 << endl;
		return 0;
	}
	int last = -1;
	call(s,n-1);
	for (int i = n - 1; ~i ; --i) {
		if (!choose[a[i].second] || !i) {
			if (last != -1) {
				ans[a[i].second].push_back(a[i].first - a[last].first);
				is[a[i].second] = 1;
				in[a[i].second] = a[last].second;
			} else ans[a[i].second].push_back(a[i].first);
			last = i;
		} else ans[a[i].second].push_back(a[i].first);
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i][0] << ' ';
		if (choose[i] && i != a[0].second) is[i] = 0;
		cout << is[i] << ' ';
		if (is[i]) cout << in[i] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}