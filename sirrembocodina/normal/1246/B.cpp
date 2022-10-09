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
     
    int a[100100];
    bool notp[100100];
    vector<int> p;
    vector<pair<int, int> > pc[100100];
    long long AAA[100100];
     
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        for (int i = 2; i < 100100; ++i) {
        	if (notp[i]) {
        		continue;
        	}
    		p.pb(i);
    		if (i > 1000) {
    			continue;
    		}
    		for (int j = i * i; j < 100100; j += i) {
    			notp[j] = true;
    		}
        }
        int n = 100000, k = 2;
        cin >> n >> k;
        long long ans = 0;
        map<long long, int> m;
        forn (q, n) {
        	int a = 30030;
        	cin >> a;
        	int aaa = a;
        	vector<pair<int, int> > v;
        	if (pc[a].size() == 0) {
	        	for (auto x: p) {
	        		if (x * x > a) {
	        			break;
	        		}
	        		if (a % x) {
	        			continue;
	        		}
	        		int cnt = 0;
	        		while (a % x == 0) {
	        			a /= x;
	        			cnt++;
	        		}
	        		cnt %= k;
	        		if (cnt) {
	    	    		v.pb(make_pair(x, cnt));
	        		}
    	    	}
	        	if (a > 1) {
	        		v.pb(make_pair(a, 1));
	        	}
    	    	pc[aaa] = v;
    	    } else {
    	    	v = pc[a];
    	    }
    		long long A = 1;
    		for (auto x: v) {
    			forn (i, k - x.sc) {
    				A *= x.fs;
    				if (A > 100000) {
    					break;
    				}
    			}
    			if (A > 100000) {
    				break;
    			}
    		}
    		ans += m[A];
    		A = 1;
    		for (auto x: v) {
    			forn (i, x.sc) {
    				A *= x.fs;
    			}
    		}
    		m[A]++;
        }
        cout << ans << endl;
    }