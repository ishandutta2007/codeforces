#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 1e6 + 5;
int n, c1, c2, p;
string t1, t2, t;
string s[60000];

string nxt(string t) {
    int p = t.length() - 1;
    while (t[p] == 'Z') {
        t[p] = 'A';
        p--;
        if (p == -1) break;
    }
    if (p == -1)
        t += 'A';
    else
        t[p]++;
    return t;
}

string get_str(int c) {
    string ans = s[c / 20];
    for (int i = 0; i < c % 20; i++)
        ans = nxt(ans);
    return ans;
}

int get_num(string k) {
    int l = 0, r = 50001, m;
    while (r - l > 1) {
        m = (r + l) / 2;
        if (s[m].length() < k.length() || (s[m].length() == k.length() && s[m] <= k))
            l = m;
        else
            r = m;
    }
    int ans = l * 20;
    string h = s[l];
    while (h != k) {
        h = nxt(h);
        ans++;
    }
    return ans;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    t = "";
    s[0] = "";
    for (int i = 1; i < N; i++) {
        t = nxt(t);
        if (i % 20 == 0)
            s[i / 20] = t;
        //cerr << t << "\n";
    }

    cin >> n;

    //t = "R999999C999999";
    //t = "BDWGM999999";

    for (int i = 0; i < n; i++) {
        cin >> t;
        p = 0;
        c1 = c2 = 0;
        t1 = t2 = "";
        while (t[p] >= 'A' && t[p] <= 'Z') t1 += t[p++];
        while (t[p] >= '0' && t[p] <= '9') c1 = c1 * 10 + t[p++] - '0';
        if (p == t.length()) {
            //cout << "R" << c1 << "C" << get_num(t1);
            printf("R%dC%d\n", c1, get_num(t1));
            continue;
        }
        while (t[p] >= 'A' && t[p] <= 'Z') t2 += t[p++];
        while (t[p] >= '0' && t[p] <= '9') c2 = c2 * 10 + t[p++] - '0';
        //cout << get_str(c2) << c1 << "\n";
        printf("%s%d\n", get_str(c2).c_str(), c1);
    }


    return 0;
}