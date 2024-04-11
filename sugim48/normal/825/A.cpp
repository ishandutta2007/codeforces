#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	vector<int> v;
	v.pb(-1);
	rep(i, N) if (s[i] == '0') v.pb(i);
	v.pb(N);
	for (int k = 0; k + 1 < v.size(); k++)
		cout << v[k + 1] - v[k] - 1;
	cout << endl;
}