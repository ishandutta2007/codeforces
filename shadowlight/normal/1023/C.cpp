#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <char> st;
    int cnt = n;
    int bal = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push_back(s[i]);
            bal++;
        } else {
            if (cnt > k) {
                cnt -= 2;
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
            bal--;
        }
    }
    for (char c : st) {
        cout << c;
    }
}