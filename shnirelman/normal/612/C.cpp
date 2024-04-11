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

    int n = s.size();

    map<char, char> other;
    other['('] = ')';
    other[')'] = '(';
    other['{'] = '}';
    other['}'] = '{';
    other['['] = ']';
    other[']'] = '[';
    other['<'] = '>';
    other['>'] = '<';


    stack<char> st;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                cout << "Impossible" << endl;
                return 0;
            }
            ans += (st.top() != other[s[i]]);
            st.pop();
        }
    }

    if(st.empty())
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
}