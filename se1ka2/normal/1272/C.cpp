#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += '.';
    bool b[30]{0};
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        b[c - 'a'] = true;
    }
    ll ans = 0, l = 0;
    for(int i = 0; i <= n; i++){
        if(b[s[i] - 'a']) l++;
        else{
            ans += l * (l + 1) / 2;
            l = 0;
        }
    }
    cout << ans << endl;
}