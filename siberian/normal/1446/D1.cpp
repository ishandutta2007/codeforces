#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10, A = 110;
int n;
int a[N];
vector<int> pos[A];
int cnt[A];

void read() {
    cin >> n;
    fill(cnt, cnt + A, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        cnt[a[i]]++;
    }
}
/*
int get(int val, int l, int r) {
    return upper_bound(all(pos[val]), r) - lower_bound(all(pos[val]), l);
}*/



int bal[2 * N];

int get(int mx, int val) {
    if (cnt[val] == 0) return 0;
    fill(bal, bal + 2 * N, 2 * N);
    bal[N] = -1;
    int now = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) {
            ++now;
        } else if (a[i] == val) {
            --now;
        }
        chkmax(ans, i - bal[now + N]);
        chkmin(bal[now + N], i);
    }
    return ans;
    /*int ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (get(mx, l, r) == get(val, l, r)) {
                chkmax(ans, r - l + 1);
            }
        }
    }
    return ans;*/
}

int ans;

void run() {
    int mx = max_element(cnt, cnt + A) - cnt;
    //cout << "mx = " << mx << endl;
    ans = 0;
    for (int i = 0; i < A; ++i) {
        if (i == mx) continue;
        chkmax(ans, get(mx, i));
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}


    /*if (!cnt[val]) return 0;
    cout << "mx = " << mx << " val = " << val << endl;
    int ans = 0;
    int posVal = 0;

    for (int i = 0; i < pos[mx].size(); ++i) {
        if (i > 0) {
            while (posVal < pos[val].size() && pos[val][posVal] < pos[mx][i - 1]) ++posVal;
        }
        int cntNow = cnt[val] - posVal;
        if (i + cntNow - 1 >= pos[mx].size()) continue;
        int len = 0;

        if (i > 0) len += pos[mx][i] - pos[mx][i - 1] - 1;
        else len += pos[mx][i];
        if (i + cntNow < pos[mx].size()) len += pos[mx][i + cntNow] - pos[mx][i] - 1;
        else len += n - 1 - pos[mx][i];
        ++len;
        
        if (len == 3) {
            cout << "i = " << i << endl;
        }
        chkmax(ans, len);
    }
    return ans;*/

/*

int pos1 = 0, pos2 = 0;
    int ans = 0;
    int nowBal = 0;
    int lastPos = 0;
    while (pos1 < pos[mx].size() && pos2 < pos[val].size()) {
        if (pos[mx][pos1] < pos[val][pos2]) {
            chkmax(ans, pos[mx][pos1] - bal[nowBal + N]);
            nowBal++;
            bal[nowBal + N] = lastPos;
            lastPos = pos[mx][pos1] + 1;
            ++pos1;
        } else {
            chkmax(ans, pos[val][pos2] - bal[nowBal + N]);
            nowBal--;
            bal[nowBal + N] = lastPos;
            lastPos = pos[val][pos2] + 1;
            ++pos2;
        }
    }
    while (pos1 < pos[mx].size()) {
        chkmax(ans, pos[mx][pos1] - bal[nowBal + N]);
        nowBal++;
        bal[nowBal + N] = lastPos;
        lastPos = pos[mx][pos1] + 1;
        ++pos1;
    }
    while (pos2 < pos[val].size()) {
        chkmax(ans, pos[val][pos2] - bal[nowBal + N]);
        nowBal--;
        bal[nowBal + N] = lastPos;
        lastPos = pos[val][pos2] + 1;
        ++pos2;
    }
    chkmax(ans, n - bal[nowBal + N]);

    */