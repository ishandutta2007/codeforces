#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    t -= (1ll << (s[n - 1] - 'a'));
    t += (1ll << (s[n - 2] - 'a'));
    ll c[26]{0};
    for(int i = 0; i < n - 2; i++) c[s[i] - 'a']++;
    ll r = 0;
    for(int i = 0; i < 26; i++) r += (c[i] << i);
    t = abs(t);
    if(r < t){
        cout << "No" << endl;
        return 0;
    }
    r -= t;
    for(int i = 25; i >= 0; i--){
        ll l = (r >> (i + 1));
        r -= (min(l, c[i]) << (i + 1));
    }
    if(r == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}