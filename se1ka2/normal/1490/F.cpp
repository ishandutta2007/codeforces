#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            mp[a]++;
        }
        int d[200005];
        for(int i = 0; i <= n; i++) d[i] = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            d[itr->second]++;
        }
        int k = 0, c = 0, s = 0, ans = n;
        for(int i = n; i >= 0; i--){
            c += d[i];
            k += d[i] * i;
            ans = min(ans, s + n - k);
            s += c;
        }
        cout << ans << endl;
    }
}