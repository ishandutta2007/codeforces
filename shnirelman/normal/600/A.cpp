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
const int N = 1e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;

    vector<string> a, b;

    string cur = "";
    bool fl = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ',' || s[i] == ';') {
            if(fl || cur == "" || cur[0] == '0' && cur.size() > 1)
                b.push_back(cur);
            else
                a.push_back(cur);
            cur = "";
            fl = false;
        } else {
            cur += s[i];
            if(s[i] < '0' || s[i] > '9')
                fl = true;
        }
    }

    if(fl || cur == "" || cur[0] == '0' && cur.size() > 1)
        b.push_back(cur);
    else
        a.push_back(cur);
    cur = "";
    fl = false;

    if(a.empty())
        cout << "-" << endl;
    else {
        cout << char(34);
        for(int i = 0; i < a.size(); i++) {
            cout << a[i];
            if(i < a.size() - 1) {
                cout << ',';
            }
        }
        cout << char(34) << endl;
    }

    if(b.empty())
        cout << "-" << endl;
    else {
        cout << char(34);
        for(int i = 0; i < b.size(); i++) {
            cout << b[i];
            if(i < b.size() - 1) {
                cout << ',';
            }
        }
        cout << char(34) << endl;
    }


}