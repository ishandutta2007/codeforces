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

pair<pair<int, int>, pair<int, int> > a[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i].fs.fs >> a[i].fs.sc >> a[i].sc.fs;
        a[i].sc.sc = i + 1;
    }
    sort(a, a + n);
    vector<bool> used(n, false);
    forn (i, n - 1) {
    	if (a[i].fs == a[i + 1].fs && !used[i] && !used[i + 1]) {
    		cout << a[i].sc.sc << " " << a[i + 1].sc.sc << endl;
    		used[i] = used[i + 1] = true;
    	}
    }
    vector<pair<pair<int, int>, pair<int, int> > > b;
    forn (i, n) {
    	if (!used[i]) {
			b.pb(a[i]);
    	}
    }
    n = b.size();
    used.assign(n, false);
    forn (i, n - 1) {
    	if (b[i].fs.fs == b[i + 1].fs.fs && !used[i] && !used[i + 1]) {
    		cout << b[i].sc.sc << " " << b[i + 1].sc.sc << endl;
    		used[i] = used[i + 1] = true;
    	}
    }
    vector<pair<pair<int, int>, pair<int, int> > > c;
    forn (i, n) {
    	if (!used[i]) {
			c.pb(b[i]);
    	}
    }
    n = c.size();
    forn (i, n / 2) {
    	cout << c[2 * i].sc.sc << " " << c[2 * i + 1].sc.sc << endl;
    }
}