#include <bits/stdc++.h>
using namespace std;
const int N = 190;
typedef long long ll;

int n;
string s;
set <char> st;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        st.insert(s[i]);
    cout << (n > 26 ? -1 : n - int(st.size()));
    return 0;
}