#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;

//int dp[N];

void solve() {
    int n;
    cin >> n;

    bool fl = false;
    for(li i = 2; i < INF; i *= 4)
        if(i == n)
            fl = true;

    cout << (n % 2 == 1 || fl ? "Bob" : "Alice") << endl;

}

int main() {

    int t;
    cin >> t;

    while(t--)
        solve();

//    dp[1] = 0;
//    for(int i = 2; i < N; i++) {
//        set<int> st;
//        for(int j = 2; j * j <= i; j++)
//            if(i % j == 0) {
//                if(dp[i - j] == 0 || dp[i - i / j] == 0)
//                    dp[i] = 1;
//                st.insert(j);
//                st.insert(i / j);
//            }
//
//        if(dp[i] == 0 && i % 2 == 0)
//            cout << i << endl;
////        if(dp[i])cout << i << ' ' << dp[i] << ' ' << st.size() % 2 << endl;
//    }

}