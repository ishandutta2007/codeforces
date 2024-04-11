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

int a[300100];
int st[300100][20];
int lg[300100];
vector<int> g[300100];

int seg_max(int l, int r) {
	if (l >= r) {
		return -2000000000;
	}
	int p = lg[r - l];
    return max(st[l][p], st[r - (1 << p)][p]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    lg[1] = 0;
    for (int i = 2; i <= 3 * n; ++i) {
    	lg[i] = lg[i - 1];
    	if ((1 << (lg[i] + 1)) == i) {
    		lg[i]++;
    	}
    }
    forn (i, n) {
    	cin >> a[i];
    	a[n + i] = a[n + n + i] = a[i];
    	st[i][0] = st[n + i][0] = st[n + n + i][0] = a[i];
    }
    for (int p = 1; p < 20; ++p) {
    	for (int i = 0; i + (1 << p) <= 3 * n; ++i) {
    		st[i][p] = max(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
    	}
    }
    bool was = false;
    set<int> s;
    forn (i, 3 * n) {
    	if (seg_max(0, 3 * n) <= 2 * a[i]) {
    		continue;
    	}
    	was = true;
    	if (seg_max(0, i) > 2 * a[i]) {
    		int l = 0, r = i;
    		while (r - l > 1) {
    			int mid = (l + r) / 2;
    			if (seg_max(mid, i) > 2 * a[i]) {
    				l = mid;
    			} else {
    				r = mid;
    			}
    		}
    		g[l].pb(i);
    		s.insert(i);
    	} else {
/*    		int l = i + 1, r = n;
    		while (r - l > 1) {
    			int mid = (l + r) / 2;
    			if (seg_max(mid, n) > 2 * a[i]) {
    				l = mid;
    			} else {
    				r = mid;
    			}
    		}*/
    		continue;
    	}
    }
    if (!was) {
    	forn (i, n) {
    		cout << -1 << " ";
    	}
    	cout << endl;
    	return 0;
    }
    forn (i, n) {
    	cout << (*s.begin()) - i << " ";
    	for (auto& x: g[i]) {
    		s.erase(x);
    	}
    }
    cout << endl;
}