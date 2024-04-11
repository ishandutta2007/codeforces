#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> st;
    int n;
    string s;
    cin >> n >> s;
    for(int off = 0; off < n; off++) {
        int sum = 0;
        string t = "0";
        for(int i = 0; i < n - 1; i++) {
            sum = (sum + s[(off + i + 1) % n] - s[(off + i) % n] + 10) % 10;
            t += ('0' + sum);
        }
        st.insert(t);
    }
    cout << *st.begin() << endl;
}