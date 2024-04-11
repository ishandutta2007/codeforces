#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int mod = 1e9 + 7;
void md(int &a) {
    if (a >= mod)
        a -= mod;
}
vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
int acntinb(string a, string b) {
    string tz = a + '?' + b;
    vector<int> z = z_function(tz);
    int res = 0;
    for (int i = a.size() + 1; i < tz.size(); ++i) {
        res += (z[i] == a.size());
    }
    return res;
}
vector<int> getnums(string s1, string s2) {
    vector<int> alph(26);
    vector<int> z = z_function(s1 + '?' + s2 + '!');
    reverse(all(s1));
    reverse(all(s2));
    vector<int> zrev = z_function(s1 + '?' + s2 + '!');
    reverse(all(s2));
    for (int j = 0; j < s2.size(); ++j) {
        int pos = j + s1.size() + 1;
        int invj = s2.size() - j - 1;
        int invpos = invj + s1.size() + 1;
        //cerr << z[pos + 1] << ' ' << zrev[invpos + 1] << endl;
        if (z[pos + 1] == s2.size() - j - 1 and zrev[invpos + 1] == s2.size() - invj - 1){
            alph[s2[j] - 'a']++;
            //cout << s2[j] << endl;
        }
    }
    return alph;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<int> pw2(n + 3);
    pw2[0] = 1;
    for (int k = 1; k < n + 3; ++k) {
        pw2[k] = pw2[k - 1] << 1;
        md(pw2[k]);
    }
    vector<string> s(1);
    cin >> s[0];
    int itti = 0;
    vector<vector<int>> letcnt(26, vector<int>(n + 1));
    string t;
    cin >> t;
    while (s.back().size() <= 1e6 and itti < n) {
        s.push_back(s.back() + t[itti] + s.back());
        itti++;
        //cerr << s.back() << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            letcnt[j][i + 1] = letcnt[j][i] << 1;
            md(letcnt[j][i + 1]);
            if (t[i] == 'a' + j) {
                letcnt[j][i + 1]++;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int tpos;
        cin >> tpos;
        string s2;
        cin >> s2;
        int reind = 0;
        while (s[reind].size() < s2.size())
            reind++;
        reind = min(reind, tpos);
        string toz = s[reind] + '?' + s2 + '!';
        int res = acntinb(s2, s[reind]) * pw2[tpos - reind] % mod;
        vector<int> z = z_function(toz);
        //cout << reind << ' ' << s[reind] << ' ' << s2 << ' ' << res << endl;
        vector<int> alphcnt = getnums(s[reind], s2);
        //cout << s2.size() << ' ' << z[s[reind].size() + 1] << endl;
        for (int k = 0; k < 26; ++k) {
            res -= alphcnt[k] * letcnt[k][reind] % mod * pw2[tpos - reind];
            res += alphcnt[k] * letcnt[k][tpos];
            res %= mod;
        }
        res += mod;
        res %= mod;
        cout << res << '\n';
    }
}
/*
3 1
aa
bcd
3 ca

2 1
aba
bbac
2 bab

 */