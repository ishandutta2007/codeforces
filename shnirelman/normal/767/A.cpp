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
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> st, b;
    for(auto x : a)
        b.insert(-x);

    for(int i = 0; i < n; i++) {
        st.insert(-a[i]);
        while(!st.empty()) {
            if(*st.begin() <= *b.begin()) {
                cout << -*st.begin() << ' ';
                st.erase(st.begin());
                b.erase(b.begin());
            } else
                break;
        }
        cout << '\n';
    }

}