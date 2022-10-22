//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

/*
*/

//int n;
//int res = INF;
//vector<int> ans;
//
//void calc(vector<int> p, vector<int> wh1, vector<int> wh2) {
//    if(p.size() == n * 2) {
//        int rs = 0;
//        for(int i = 0; i < n; i++) {
//            rs += (n - i - 1) * abs(wh2[i] - wh1[i] + i + 1 - n);
//        }
//
//        if(rs < res) {
//            res = rs;
//            ans = p;
//        }
//
//        return;
//    }
//
//    p.push_back(0);
//    for(int i = 0; i < n; i++) {
//        p.back() = i;
//        if(wh1[i] == -1) {
//            wh1[i] = p.size() - 1;
//            calc(p, wh1, wh2);
//            wh1[i] = -1;
//        } else if(wh2[i] == -1) {
//            wh2[i] = p.size() - 1;
//            calc(p, wh1, wh2);
//            wh2[i] = -1;
//        }
//
//
//    }
//}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> ans;
    vector<int> p;
    for(int i = n - 1; i > 0; i -= 2) {
        p.push_back(i);
    }
    reverse(p.begin(), p.end());
    for(auto x : p)
        ans.push_back(x);
    reverse(p.begin(), p.end());
    for(auto x : p)
        ans.push_back(x);
    ans.push_back(n);

    p.erase(p.begin(), p.end());
    for(int i = n - 2; i > 0; i -= 2) {
        p.push_back(i);
    }
    reverse(p.begin(), p.end());
    for(auto x : p)
        ans.push_back(x);
    ans.push_back(n);
    reverse(p.begin(), p.end());
    for(auto x : p)
        ans.push_back(x);

    for(auto x : ans)
        cout << x << ' ';
    cout << endl;

//    cin >> n;
//
//    calc(vector<int>(0), vector<int>(n, -1), vector<int>(n, - 1));
//
//    cout << res << endl;
//    for(auto x : ans)
//        cout << x + 1 << ' ';
//    cout << endl;
}