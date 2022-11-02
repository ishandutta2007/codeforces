#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 1010

int a[N];
vector <pii> ans;

void solve(vector <int> &idx) {
	int n = idx.size();
    if(n < 2) return;
	int mx = 0, mid;
	for(int i = n-1; i >= 0; i --) if(a[idx[i]] > mx) mx = a[idx[i]], mid = i;
    vector <int> jdx;
    for(int i = 0; i < n; i ++) if(i != mid) jdx.push_back(idx[i]);
    solve(jdx);
    for(int i = n-1; i > mid; i --) {
        swap(a[idx[mid]], a[idx[i]]);
        ans.push_back(pii(idx[mid], idx[i]));
    }
}

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	vector <int> idx(n);
	for(int i = 0; i < n; i ++) idx[i] = i+1;
	solve(idx);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++) cout << ans[i].first << ' ' << ans[i].second << endl;
}