#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> p(n + 1, 0);
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (s[i - 1] == '[');

//    for(int i = 0; i <= n; i++)
//        cout << i << ' ' << p[i] << endl;

    map<char, char> mp;
    mp['('] = ')';
    mp[')'] = '(';
    mp['['] = ']';
    mp[']'] = '[';

    stack<int> st;
    int l = -1, r = -1, ans = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << n << endl;
        if(s[i] == ')' || s[i] == ']') {
            if(!st.empty() && s[st.top()] == mp[s[i]]) {
                st.pop();
                int res = p[i + 1] - p[st.empty() ? 0 : st.top() + 1];
                if(res > ans) {
                    ans = res;
                    l = st.empty() ? 0 : st.top() + 1;
                    r = i + 1;
//                    cout << l << ' ' << r << ' ' << ans << ' ' << p[l] << ' ' << p[r] << endl;
                }
            } else {
                st.push(i);
            }
        } else {
            st.push(i);
        }


    }

    cout << ans << endl;
    for(int i = l; i < r; i++)
        cout << s[i];
}