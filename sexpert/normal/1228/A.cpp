#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(int x) {
    string s = to_string(x);
    set<char> ss;
    for(auto c : s)
        ss.insert(c);
    return ss.size() == s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, r;
    cin >> l >> r;
    for(int x = l; x <= r; x++)
        if(good(x))
            {
                cout << x << '\n';
                return 0;
            }
    cout << "-1\n"; 
}