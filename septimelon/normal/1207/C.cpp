#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> upl;
    vector<int> upr;
    int t;
    ll n, a, b;
    string s;
    cin >> t;
    bool up;
    ll ans;
    for (int qq = 0; qq < t; qq++) {
        cin >> n >> a >> b >> s;
        up = false;
        ans = (n+1) * b + n * a;
        upl.clear();
        upr.clear();
        for (int i = 0; i < s.size(); i++) {
            if (up && s[i] == '0') {
                up = false;
                upr.push_back(i);
                ans += (upr[upr.size()-1] - upl[upl.size()-1] + 1) * b + 2 * a;
            }
            if (!up && s[i] == '1') {
                up = true;
                upl.push_back(i);
            }
        }
        //cout << ans << " - ";
        for (int i = 1; i < upl.size(); i++) {
            if (2 * a > b * (upl[i] - upr[i-1] - 1)) {
                ans -= 2 * a;
                ans += b * (upl[i] - upr[i-1] - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}