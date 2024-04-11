#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5 + 13;
const int A = 1e6 + 13;
 
vector<int> divs[A];
int a[N];
 
int gr_lf[N], gr_rg[N];
int less_lf[N], less_rg[N];
 
vector<int> pos[A];
int ind[A];
 
void solve() {
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
 
    {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[st.top()] < a[i])
                st.pop();
 
            gr_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }
 
    {
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && a[st.top()] <= a[i])
                st.pop();
 
            gr_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }
 
    {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && a[st.top()] >= a[i])
                st.pop();
 
            less_lf[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }
 
    {
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && a[st.top()] >= a[i])
                st.pop();
 
            less_rg[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }
 
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int x : divs[a[i]]) {
            if(ind[x] >= 1) {
                int j = pos[x][ind[x] - 1];
                if(j > gr_lf[i] && less_rg[j] > i) {
                    ans += (j - max(gr_lf[i], less_lf[j])) * 1ll * (min(gr_rg[i], less_rg[j]) - i);
                }
            }
 
            if(ind[x] < pos[x].size()) {
                int j = pos[x][ind[x]];
                if(j < gr_rg[i] && less_lf[j] < i) {
                    ans += (i - max({gr_lf[i], less_lf[j], ind[x] >= 1 ? pos[x][ind[x] - 1] : -1})) * 1ll * (min(gr_rg[i], less_rg[j]) - j);
                }
 
            }
        }
 
        ind[a[i]]++;
    }
 
    cout << ans << endl;
 
    for(int i = 0; i < n; i++) {
        pos[a[i]].erase(pos[a[i]].begin(), pos[a[i]].end());
        gr_lf[i] = gr_rg[i] = less_lf[i] = less_rg[i] = 0;
        ind[a[i]] = 0;
    }
}
 
int main() {
    for(int i = 1; i < A; i++) {
        for(int j = i; j < A; j += i)
            divs[j].push_back(i);
    }
 
    int t;
    cin >> t;
 
    while(t--)
        solve();
}