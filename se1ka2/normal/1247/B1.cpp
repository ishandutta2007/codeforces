#include <iostream>
#include <vector>
#include <map>
using namespace std;

int a[200005];

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, k, d;
        cin >> n >> k >> d;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<int, int> mp;
        for(int i = 0; i < d; i++) mp[a[i]]++;
        int ans = mp.size();
        for(int i = d; i < n; i++){
            mp[a[i]]++;
            mp[a[i - d]]--;
            if(mp[a[i - d]] == 0) mp.erase(a[i - d]);
            ans = min(ans, (int)mp.size());
        }
        cout << ans << endl;
    }
}