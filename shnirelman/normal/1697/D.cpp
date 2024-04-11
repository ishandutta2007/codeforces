#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 32 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;


//string S = "";
//int cnt1 = 0, cnt2 = 0;
//
//char get1(int i) {
//    cnt1++;
//    return S[i];
//}
//
//int get2(int l, int r) {
//    cnt2++;
//    set<char> st(S.begin() + l, S.begin() + r);
//    return st.size();
//}

char get1(int i) {
    cout << "? 1 " << i + 1 << endl;
    char c;
    cin >> c;
    return c;
}

int get2(int l, int r) {
    cout << "? 2 " << l + 1 << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}

mt19937 rnd(0);

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

//    for(int i = 0; i < n; i++) {
//        S += char('a' + rnd() % 26);
//    }

    string ans = "";

    vector<int> pos;
    for(int i = 0; i < n; i++) {
        int l = -1, r = pos.size();
        while(r - l > 1) {
            int m = (l + r) / 2;

            int res = get2(pos[m], i + 1);
            if(res == m + 1)
                r = m;
            else
                l = m;
        }

        if(r == pos.size()) {
            ans += get1(i);
            pos.insert(pos.begin(), i);
        } else {
            ans += ans[pos[r]];
            char c = ans.back();
            pos.erase(pos.begin() + r);
            pos.insert(pos.begin(), i);
        }
    }

//    cout << S << endl;
    cout << "! " << ans << endl;
//    cout << (ans == S) << endl;
//    cout << cnt1 << ' ' << cnt2 << endl;

//    for(int i : pos) {
//        cout << ans[i] << ' ' << i << endl;
//    }
//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}