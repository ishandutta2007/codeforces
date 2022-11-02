#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int a, b, c, d;

void read() {
    cin >> a >> b >> c >> d;
}

string ans = "";

void no() {
    cout << "NO" << endl;
    exit(0);
}

void yes(string s) {
    cout << "YES\n";
    for (auto i : s)
        cout << i << " ";
    exit(0);
}

void run() {
    if (d == c + 1) {
        if (a || b)
            no();
        string ans = "";
        for (int i = 0; i < c; i++)
            ans += "32";
        ans += "3";
        yes(ans);
    }
    if (a == b + 1) {
        if (d || c) {
            no();
        }
        string ans = "";
        for (int i = 0; i < b; i++)
            ans += "01";
        ans += "0";
        yes(ans);
    }   
    if (a > b + 1 || d > c + 1) no();
    if (a > b && d > c) no();
    
    string a1 = "";
    for (int i = 0; i < a; i++)
        a1 += "01";
    b -= a;

    string a2 = "";
    for (int i = 0; i < d; i++)
        a2 += "23";
    c -= d;


    string a3 = "";
    int x = min(b, c);

    for (int i = 0; i < x; i++)
        a3 += "21";
    
    string ans = a1 + a3 + a2;
    b -= x;
    c -= x;
    if (c > 1 || b > 1)
        no();
    if (c) ans += "2";
    else if (b) ans = "1" + ans;
    
    yes(ans);
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