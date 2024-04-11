#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int LOGN = 20;

vector<pair<int, string>> a;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<pair<int, string>> st(a.begin(), a.end());
//    for(auto x : st)
//        cout << x << endl;
//    cout << st.size() << endl;
    for(int i = 0; i < n; i++) {
        st.erase({1, s.substr(i, 1)});
    }
//cout << st.size() << endl;
    for(int i = 0; i < n - 1; i++) {
        st.erase({2, s.substr(i, 2)});
    }
//cout << st.size() << endl;
    for(int i = 0; i < n - 2; i++) {
        st.erase({3, s.substr(i, 3)});
    }
//cout << st.size() << endl;
    cout << st.begin()->s << endl;
}

int main() {

    for(char c = 'a'; c <= 'z'; c++) {
        string s = "";
        s += c;
        a.push_back({1, s});
    }

    for(char c = 'a'; c <= 'z'; c++) {
        for(char c1 = 'a'; c1 <= 'z'; c1++) {
            string s = "";
            s += c;
            s += c1;
            a.push_back({2, s});
        }
    }

    for(char c = 'a'; c <= 'z' && a.size() < 2000; c++) {
        for(char c1 = 'a'; c1 <= 'z' && a.size() < 2000; c1++) for(char c2 = 'a'; c2 <= 'z'; c2++){
            string s = "";
            s += c;
            s += c1;
            s += c2;
            a.push_back({3, s});
//            if(a.size() > 2000)

        }
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}