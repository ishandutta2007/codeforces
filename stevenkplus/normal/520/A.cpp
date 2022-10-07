#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin >> n;
string s;
cin >> s;
set<char> st;
for(int i = 0; i < n; ++i) {
char c = s[i];
if (c >= 'a') c -= ('a' - 'A');
st.insert(c);
}
if (st.size() == 26) {
cout << "YES\n";
} else {
cout << "NO\n";
}
}