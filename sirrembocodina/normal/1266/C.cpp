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

int n;

vector<long long> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
   		cout << 0 << endl;
   		return 0;
    }
    if (n == 1) {
    	forn (i, m) {
    		cout << 2 + i << " ";
    	}
    	cout << endl;
    	return 0;
    }
    if (m == 1) {
    	forn (i, n) {
    		cout << 2 + i << endl;
    	}
    	return 0;
    }
    forn (i, n) {
    	forn (j, m) {
    		cout << (1 + i) * (n + 1 + j) << " ";
    	}
	    cout << endl;
    }
}