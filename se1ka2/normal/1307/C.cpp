#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll s[26][100002];

int main()
{
    string t;
    cin >> t;
    int n = t.size();
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++) s[j][i] = s[j][i - 1];
        s[t[i - 1] - 'a'][i]++;
    }
    ll ans = 0;
    for(int j = 0; j < 26; j++) ans = max(ans, s[j][n]);
    for(int j = 0; j < 26; j++){
        for(int k = 0; k < 26; k++){
            ll r = 0;
            for(int i = 0; i < n; i++){
                if(t[i] == 'a' + j) r += s[k][n] - s[k][i + 1];
            }
            ans = max(ans, r);
        }
    }
    cout << ans << endl;
}