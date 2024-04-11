#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lef() {
    ll ans = 0;
    for (int i = 0; i < 7; i++) {
        ans *= 2;
        ans ++;
    }
    return ans;
}

ll sev() {
    ll ans = 1;
    for (int i = 0; i < 7; i++)
        ans *= 2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll left, right, seven0;
    left = lef();
    seven0 = sev();
    right = left * seven0;
    ll ansl, ansr;
    cout << "?";
    for (ll i = 0; i < 100; i++)
        cout << " " << left + seven0 * i;
    cout << endl;
    fflush(stdout);
    cin >> ansl;
    ansl = (ll)(ansl&left);
    cout << "?";
    for (ll i = 0; i < 100; i++)
        cout << " " << right + i;
    cout << endl;
    fflush(stdout);
    cin >> ansr;
    ansr = (ll)(ansr&right);
    //cout << ansl + ansr << endl;
    ll ans = (ll)((ansl+ansr)^(left+right));
    cout << "! " << ans << endl;
    return 0;
}