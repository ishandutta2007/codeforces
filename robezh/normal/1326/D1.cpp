#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e6 + 50, INF = (int)1e9;


struct Manacher {
    string s, sn;
    int p[2*N];

    int Init() {
        int len = s.length();
        sn = "$#";
        int j = 2;

        for (int i = 0; i < len; i++)
        {
            sn.push_back(s[i]);
            sn.push_back('#');
        }

        sn.push_back('\0');

        return sn.length();
    }

    int run() {
        int len = Init();
        int max_len = -1;

        int id = 0;
        int mx = 0;

        for (int i = 1; i < len; i++)
        {
            if (i < mx) p[i] = min(p[2 * id - i], mx - i);
            else p[i] = 1;

            while (sn[i - p[i]] == sn[i + p[i]]) p[i]++;

            if (mx < i + p[i]) id = i, mx = i + p[i];

            max_len = max(max_len, p[i] - 1);
        }
        return max_len;
    }

    void solve() {
        cin >> s;
        int n = s.length();
        run();
//        cout << sn << endl;
//        for(int i = 0; i < sn.length(); i++) cout << p[i] << " ";
//        cout << endl;
        int len = -INF,
        mid = -1, min_ext = -1, res = -INF;
        for(int i = 0; i * 2 <= n; i++) {
            int l = ((i - 1) + 1) * 2, r = ((n - i) + 1) * 2;
//            cout << i << ": " << l << ", " << r << endl;
            for(int x = l + 2; x <= r - 2; x++) {
                int ext = min(p[x], min(r - x, x - l));
//                cout << x << " " << ext << endl;
//                cout << "len: " << i << " ext:" << ext << endl;
//                if(ext == min(r - x, x - l)) {
                if(x + ext == r || x - ext == l) {
                    int curres = (ext - 1) + 2 * i;
                    if(curres > res) {
                        res = curres;
                        len = i, mid = x, min_ext = ext;
//                        cout << len << " " << mid << " " << min_ext << endl;
                    }
                }
            }
            if(s[i] != s[n - i - 1]) break;
        }
//        cout << res << endl;

        for(int i = 0; i < len; i++) cout << s[i];
        for(int x = mid - min_ext + 1; x <= mid + min_ext - 1; x++) {
            if(sn[x] != '#') cout << sn[x];
        }
        for(int i = n - len; i < n; i++) cout << s[i];
        cout << '\n';





    }
} mnc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        mnc.solve();
    }
}