#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

long long ans[100100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, p;
    cin >> n >> p;
	set<pair<long long, int> > e;
	set<int> w;
	set<int> q;
	forn (i, n) {
		int t;
		cin >> t;
		e.insert(make_pair(t, i));
	}
	long long last = 0;
	while (!e.empty()) {
		long long t = e.begin()->fs;
		int i = e.begin()->sc;
		e.erase(e.begin());
		if (i >= 0) {
			w.insert(i);
		} else {
			q.erase(-i - 1);
		}
		while (!e.empty() && e.begin()->fs == t) {
			i = e.begin()->sc;
			e.erase(e.begin());
			if (i >= 0) {
				w.insert(i);
			} else {
				q.erase(-i - 1);
			}
		}
		if (w.empty()) {
			continue;
		}
		i = *w.begin();
		if (!q.empty() && i > *q.begin()) {
			continue;
		}
		w.erase(w.begin());
		ans[i] = max(last, t) + p;
		last = ans[i];
		q.insert(i);
		e.insert(make_pair(last, -i - 1));
	}
	forn (i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
}