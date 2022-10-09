#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

int a[200100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    int cnt = 0;
    forn (i, n) {
        cin >> a[i];
        if (a[i] % 2) {
        	++cnt;
        }
    }
    cnt /= 2;
    forn (i, n) {
    	if (a[i] % 2 == 0) {
    		cout << a[i] / 2 << endl;
    	} else if (cnt) {
    		if (a[i] > 0) {
	    		cout << a[i] / 2 << endl;
    		} else {
	    		cout << a[i] / 2 - 1 << endl;
    		}
    		cnt--;
    	} else {
    		if (a[i] > 0) {
	    		cout << a[i] / 2 + 1 << endl;
    		} else {
	    		cout << a[i] / 2 << endl;
    		}
    	}
    }
}