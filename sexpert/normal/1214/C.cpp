#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, mn = 0;
    string s;
    cin >> n >> s;
    vector<int> pref(1);
    for(int i = 0; i < n; i++) {
        pref.push_back(pref.back() + (s[i] == '(') - (s[i] == ')'));
        mn = min(mn, pref.back());
    }
    if(mn < -1 || pref.back() != 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
}