#include <iostream>
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
        map<int, int> mp;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            a -= i;
            ans += mp[a];
            mp[a]++;
        }
        cout << ans << endl;
    }
}