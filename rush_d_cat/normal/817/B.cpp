#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int NICO = 100000+10;
int n, a[NICO];
map<int, LL> mp;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        mp[a[i]] ++;
    }
    sort(a+1, a+1+n);
    LL ans = 0;
    if(a[1]!=a[2] && a[2]!=a[3]) {
        ans = mp[a[1]] * mp[a[2]] * mp[a[3]];
    }
    if(a[1]==a[2] && a[2]!=a[3]) {
        ans = mp[a[1]] * (mp[a[2]]-1) * mp[a[3]] / 2;
    }
    if(a[1]!=a[2] && a[2]==a[3]) {
        ans = mp[a[1]] * mp[a[2]] * (mp[a[3]]-1) / 2;
    }
    if(a[1]==a[2] && a[2]==a[3]) {
        ans = mp[a[1]] * (mp[a[2]]-1) * (mp[a[3]]-2) / 6;
    }        
    cout << ans << endl;
}