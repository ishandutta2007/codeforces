#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e3;
const int inf = 1e9;

string s[N];

int a[N], tot[N], num[N];

vector<string> vec;
vector<int> fn;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i];
		vec.push_back(s[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i] == s[j]) tot[i] += a[j];
		}
    }
    int ma = 0;
    for (int i = 0; i < vec.size(); i++) ma = max(ma, tot[i]);
    for (int i = 0; i < vec.size(); i++) {
		if (ma == tot[i]) fn.push_back(i);
    }
    memset(tot, 0, sizeof tot);
    for (int i = 0; i < fn.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (vec[fn[i]] == s[j]) {
				tot[fn[i]] += a[j];
				if (tot[fn[i]] >= ma) {
					num[fn[i]] = j; break;
				}
			}
		}
    }
    int hn = inf;
    for (int i = 0; i < fn.size(); i++) {
		hn = min(hn, num[fn[i]]);
    }
    for (int i = 0; i < fn.size(); i++) {
		if (num[fn[i]] == hn) return cout << vec[fn[i]] << endl, 0;
    }
	return 0;
}