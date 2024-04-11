#include <algorithm>
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
        map<int, int> mp[2];
        int a[100005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[i % 2][a[i]]++;
        }
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            mp[i % 2][a[i]]--;
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if(mp[i % 2][a[i]] != 0) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}