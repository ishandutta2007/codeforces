#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> cnt(n + 1);
        for (auto x : A) cnt[x]++;
        int mex = 0;
        while (cnt[mex]) mex++;
        vector<int> ans;
        while (mex != n) {
            cnt[A[mex]]--;
            cnt[mex]++;
            ans.pb(mex);
            A[mex] = mex;
            mex = 0;
            while (cnt[mex]) mex++;
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i) {
                for (int j = 0; j < n; j++) {
                    if (A[j] == i) {
                        ans.pb(j);
                        cnt[A[j]]--;
                        cnt[mex]++;
                        A[j] = mex;
                        mex = 0;
                        while (cnt[mex]) mex++;
                        break;
                    }
                }
                ans.pb(i);
                cnt[A[i]]--;
                cnt[mex]++;
                A[i] = mex;
                mex = 0;
                while (cnt[mex]) mex++;
            }
        }
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';

    }
}