#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> pf[2];

int find_first(int l, int r, int t) {
    if(l > r || pf[t][r] - pf[t][l - 1] == 0) return -1;
    int lo = l, hi = r;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(pf[t][mi] - pf[t][l - 1])
            hi = mi;
        else
            lo = mi + 1;
    }
    return lo;
}

int find_last(int l, int r, int t) {
    if(l > r || pf[t][r] - pf[t][l - 1] == 0) return -1;
    int lo = l, hi = r;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(pf[t][mi] - pf[t][l - 1])
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, ct0 = 0, ct1 = 0;
    pf[0].push_back(0);
    pf[1].push_back(0);
    cin >> n >> k;
    string s;
    cin >> s;
    for(auto c : s) {
        if(c == '0') ct0++;
        if(c == '1') ct1++;
        pf[0].push_back(pf[0].back() + (c == '0'));
        pf[1].push_back(pf[1].back() + (c == '1'));
    }

    bool sec_win = true;

    for(int p = 0; p + k <= n; p++) {
        if(pf[1][p + k] - pf[1][p] == ct1 || pf[0][p + k] - pf[0][p] == ct0) {
            cout << "tokitsukaze\n";
            return 0;
        }
        int fst = -1, lst = -1;
        int x = find_first(1, p, 0), y = find_last(p + k + 1, n, 0);
        if(x != -1)
            fst = x;
        else
            fst = find_first(p + k + 1, n, 0);
        if(y != -1)
            lst = y;
        else
            lst = find_last(1, p, 0);
        if(lst - fst >= k) {
            //cout << x << " " << y << " ded at " << p << " with 0\n";
            sec_win = false;
        }

        fst = -1, lst = -1;
        x = find_first(1, p, 1), y = find_last(p + k + 1, n, 1);
        if(x != -1)
            fst = x;
        else
            fst = find_first(p + k + 1, n, 1);
        if(y != -1)
            lst = y;
        else
            lst = find_last(1, p, 1);
        if(lst - fst >= k) { 
            //cout << x << " " << y << " ded at " << p << " with 1\n";
            sec_win = false;
        }
    }

    if(sec_win)
        cout << "quailty\n";
    else
        cout << "once again\n";
}