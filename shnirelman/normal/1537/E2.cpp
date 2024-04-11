#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int p = 43;
const int N = 1000 + 13;
//
//struct Hash {
//    int n;
//    string s;
//    vector<int> pw, h;
//
//    Hash(string t) : s(t), n(t.size()) {
//        h.resize(n + 1, 0);
//        pw.resize(n + 1, 1);
//
//        for(int i = 1; i <= n; i++) {
//            pw[i] = pw[i - 1] * 1ll * p % M;
//        }
//
//        for(int i = 1; i <= n; i++) {
//            h[i] = (h[i - 1] * 1ll * p + s[i] - 'a' + 1) % M;
//        }
//    }
//
//    int get()
//};

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string t = "" + s[0];
    int lst = 1;
//    vector<>
    for(int i = 1; i < n; i++) {
        if(s[i] < s[i % lst]) {
//            t += s[i];
            lst = i + 1;
        } else if(s[i] > s[i % lst])
            break;
        else {

        }

    }
    for(int i = 0; i < k; i++)
        cout << s[i % lst];
//    for(int i = 1; i < n; i++) {
//        if(s[i] < s[i - 1]) {
//            lst = i;
//        } else if(s[i] > s[i - 1])
//            break;
//    }
//
//    for(int i = 0; i < k; i++)
//        cout << s[i % (lst + 1)];

//    vector<int> p(n, 0);
//    string t = "" + s[0];
//    for(int i = 1; i < n;i++) {
//
//        p[i] = p[i - 1];
//        while(p[i] > 0 && s[i] != s[p[i]])
//            p[i] = p[p[i] - 1];
//
//        if(s[i] == s[p[i]])
//            p[i]++;
//
//        if(s[i] <= s[p[i]])
//    }

//    string mn = "";
//    for(int i = 0; i < k; i++)
//        mn += s[0];
//    string t = "";
//    for(int i = 0; i < n; i++) {
//        t += s[i];
//        string r = "";
//        for(int j = 0; j < k; j++)
//            r += t[j % t.size()];
//        mn = min(mn, r);
//    }
//
//    cout <<mn << endl;



}