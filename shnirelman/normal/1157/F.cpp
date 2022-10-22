//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

int cnt[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 1, resl, resr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
        resl = resr = x;
    }


    int l = 0;
    int cur = 0;
    for(int i = 0; i < N; i++) {
        if(cnt[i] == 0) {
            cur = 0;
            l = i;
        } else {
            if(cur == 0) {
                l = i;
            }
            cur += cnt[i];

            if(ans < cur) {
                ans = cur;
                resl = l;
                resr = i;
            }

            if(cnt[i] == 1 && l < i) {
                l = i;
                cur = cnt[i];
            }
        }
    }

    cout << ans << endl;
    for(int i = resl; i <= resr; i++) {
        cout << i << ' ';
    }

    for(int i = resr; i >= resl; i--) {
        for(int j = 0; j < cnt[i] - 1; j++)
            cout << i << ' ';
    }
    cout << endl;
}