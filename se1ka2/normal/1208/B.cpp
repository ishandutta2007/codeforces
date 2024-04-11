#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[2003];
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    int l;
    for(l = 0; l < n; l++){
        if(mp[a[l]] == 0) mp[a[l]]++;
        else break;
    }
    if((int)mp.size() == n){
        cout << 0 << endl;
        return 0;
    }
    int r;
    for(r = n - 1; r >= l; r--){
        if(mp[a[r]] == 0) mp[a[r]]++;
        else break;
    }
    int les = r + 1 - l;
    while(l >= 0){
        l--;
        mp[a[l]] = 0;
        while(mp[a[r]] == 0){
            mp[a[r]] = 1;
            r--;
        }
        les = min(les, r + 1 - l);
    }
    cout << les << endl;
}