//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    string s;
    getline(cin, s);
    getline(cin, s);

    int l = 1, r = s.length();
    while(r - l > 1) {
        int m = (l + r) / 2;

//        cout << endl;
//        cout << l << ' ' <<m << ' ' << r << endl;

        int cnt = 0;
        int cur = 0;
        int lst = -1;
        bool fl = false;
        for(int i = 0; i < s.length(); i++) {
//            cout << "for " << i << ' ' << cur << ' ' << lst << ' ' << cnt << endl;
            if(s[i] == '-' || s[i] == ' ') {
                if(i - lst > m) {
                    fl = true;
                    break;
                } else if(cur + i - lst > m) {
                    cur = i - lst;
                    cnt++;
                    lst = i;
                } else {
                    cur += i - lst;
                    lst = i;
                }
            }

//            cout << "for " << i << ' ' << cur << ' ' << lst << ' ' << cnt << endl;
        }

        if(s.length() - 1 - lst > m)
            fl = true;

        cnt++;
        if(cur + s.length() - 1 - lst > m)
            cnt++;

//        cout << fl << ' ' << cnt << endl;

        if(fl || cnt > k)
            l = m;
        else
            r = m;
    }

    cout << r << endl;
}