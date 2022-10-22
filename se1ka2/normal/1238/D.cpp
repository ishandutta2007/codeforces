#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> va, vb;
    ll ans = n * (n + 1) / 2;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A') va.push_back(i);
        else vb.push_back(i);
    }
    va.push_back(n);
    vb.push_back(n);
    for(int i = 0; i < (int)va.size() - 1; i++){
        if(va[i] + 1 == va[i + 1]) ans -= 2;
        else ans -= va[i + 1] - va[i];
    }
    for(int i = 0; i < (int)vb.size() - 1; i++){
        if(vb[i] + 1 == vb[i + 1]) ans -= 2;
        else ans -= vb[i + 1] - vb[i];
    }
    char r = s[n - 1];
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == r) ans++;
        else break;
    }
    cout << ans << endl;
}