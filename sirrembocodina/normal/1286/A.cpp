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

int f(int c, vector<int>& cc, vector<int>& cc0) {
    int best = 100000;
    forn (i, cc0.size() + 1) {
    	int x = c;
    	forn (j, i) {
    		x -= cc0[j];
    	}
    	if (x < 0) {
    		break;
    	}
    	int cur = int(cc0.size()) - i + int(cc.size()) * 2;
    	forn (j, cc.size()) {
    		if (x >= cc[j]) {
    			x -= cc[j];
    			cur -= 2;
    		}
    	}
    	best = min(best, cur);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    forn (i, n) {
    	cin >> a[i];
    	--a[i];
    }
    int c = 0, nc = 0;
    forn (i, n) {
    	bool was = false;
    	forn (j, n) {
    		if (a[j] == i) {
    			was = true;
    		}
    	}
    	if (was) {
    		continue;
    	}
    	if (i % 2) {
    		nc++;
    	} else {
    		c++;
    	}
    }
    if (c + nc == n) {
    	cout << int(n > 1) << endl;
    	return 0;
    }
    int ans = 0;
    vector<int> cc, ncc;
    vector<int> cc0, ncc0;
    int cur = -1;
    int len = 0;
    forn (i, n) {
    	if (a[i] == -1) {
    		len++;
    		continue;
    	}
    	if (a[i] % 2 == 0) {
    		if (cur == 0) {
    			cc.pb(len);
    		} else if (cur == -1) {
    			cc0.pb(len);
    		} else {
    			ans++;
    		}
    	} else {
    		if (cur == 1) {
    			ncc.pb(len);
    		} else if (cur == -1) {
    			ncc0.pb(len);
    		} else {
    			ans++;
    		}
    	}
    	cur = a[i] % 2;
    	len = 0;
    }
    if (cur % 2 == 0) {
    	cc0.pb(len);
    } else {
    	ncc0.pb(len);
    }
    sort(cc.begin(), cc.end());
    sort(ncc.begin(), ncc.end());
    sort(cc0.begin(), cc0.end());
    sort(ncc0.begin(), ncc0.end());
    cout << ans + f(c, cc, cc0) + f(nc, ncc, ncc0) << endl;
}