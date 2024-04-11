#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string p;
        cin >> p;
        int a[100005];
        for(int i = 0; i < n; i++){
            a[i] = p[i] - '1';
        }
        int s[100005];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        map<int, ll> mp;
        ll ans = 0;
        for(int i = n; i >= 0; i--){
            ans += mp[s[i]];
            mp[s[i]]++;
        }
        cout << ans << endl;
    }
}