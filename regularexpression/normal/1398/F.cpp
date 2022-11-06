#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
string s;
int go[N];
vector<int> here[N];
int sz[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int last0 = n, last1 = n;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') last0 = i;
        if (s[i] == '1') last1 = i;
        go[i] = max(last0, last1) - i;
    }
    vector<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && go[st.back()] <= go[i]) st.pop_back();
        st.push_back(i);
        here[i] = st;
        sz[i] = st.size();
    }
    for (int x = 1; x <= n; ++x) {
        int i = 0, ans = 0;
        while (i < n) {
            while (!here[i].empty() && go[here[i].back()] < x) here[i].pop_back();
            if (here[i].empty()) break;
            ++ans;
            i = here[i].back() + x;
        }
        cout << ans << " "[x == n];
    }
    return 0;
}