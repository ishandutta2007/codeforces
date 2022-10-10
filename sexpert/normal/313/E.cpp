#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ctt(m), ctb(m);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ctt[x]++;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ctb[m - 1 - x]++;
    }
    stack<int> st;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < ctt[i]; j++)
            st.push(i);
        for(int j = 0; j < ctb[i]; j++) {
            if(!st.empty() && st.top() < m) {
                int x = st.top();
                st.pop();
                ans.push_back(m - 1 - i + x);
            }
            else
                st.push(m + i);
        }
    }
    vector<int> toptrash;
    vector<int> bottrash;
    while(!st.empty()) {
        int t = st.top();
        st.pop();
        if(t < m)
            toptrash.push_back(t);
        else
            bottrash.push_back(t - m);
    }
    int s = toptrash.size();
    for(int i = 0; i < s; i++)
        ans.push_back(toptrash[i] - bottrash[s - i - 1] - 1);
    sort(ans.rbegin(), ans.rend());
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}