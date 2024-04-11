//
//  main.cpp
//  CP
//
//  Created by richard_bachman
//

#include <bits/stdc++.h>
#include <iostream>

const int MOD = 1000000007;

#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define ROF(i,b,a) for(int i=(b); i>=(a); i--)
#define pint pair<int, int>
#define vbool vector<int>
#define vint vector<int>
#define vpint vector<pint>
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
 
using namespace std;

//class ClassName {
//public:
//};

// readArray (&)
// printArray ()

void solve() {
    int n; cin >> n;
    long long q; cin >> q;
    vector<long long> a(n); FOR(i,0,n-1) { cin >> a[i]; }
    
    if (q >= n) {
        FOR(i,0,n-1) cout << "1"; cout << "\n"; return;
    }
    
    vector<long long> min_to_get_all(n);
    vector<long long> how_many_suf_with(n+10);
    min_to_get_all[n-1] = 1;
    int suf_len = 1;
    ROF(i,n-2,0) {
        suf_len++;
        min_to_get_all[i] = min_to_get_all[i+1] + ((min_to_get_all[i+1] >= a[i]) ? 0 : 1);
    }
    
    FOR(i,0,n-1) {
        if (q >= a[i]) {
            cout << "1";
            continue;
        }
        if (q == 0) {
            cout << "0";
            continue;
        }
        // bin search
        long skip_ans = 0;
        
        int l = i + 1;
        int r = n;
        
        if (l == r) {
            if (min_to_get_all[l] > q) { l++; }
        }
        
        while (l < r) {
            int mid = (l + r) / 2;
            if (min_to_get_all[mid] > q) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l == n) { skip_ans = 0;} else { skip_ans = n - l; }
        
        
        // bin search
        long take_ans = 0;
        
        l = i + 1;
        r = n;
        if (l == r) {
            if (min_to_get_all[l] > q - 1) { l++; }
        }
        
        while (l < r) {
            int mid = (l + r) / 2;
            if (min_to_get_all[mid] > q - 1) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l == n) { take_ans = 1; } else { take_ans = 1 + n - l; }
    
        if (take_ans > skip_ans) {
            cout << "1";
            q--;
        } else {
            cout << "0";
        }
    }
    
    cout << "\n";
    
    
}

int main() {
    // cout << "good morning, world!" << "\n";
    
    int t; cin >> t;
    FOR(i,0,t-1) {
        solve();
    }
    
//    ClassName c;
//    // input = ...
//    cout << c.method(input) << "\n";
    
    return 0;
}