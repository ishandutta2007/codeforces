#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

int a[sz];
map <int,int> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=0; i<2*n; i++) cin >> a[i];

        int ans=2*n, x=0, y=0;
        mp.clear();
        mp[0]=n;
        for(int i=2*n-1; i>=n; i--) {
            if(a[i]==1) x++;
            else y++;
            mp[x-y]=i-n;
        }
        x=0, y=0;
        if(mp.find(0)!=mp.end()) ans=n+mp[0];
        for(int i=0; i<n; i++) {
            if(a[i]==1) x++;
            else y++;
            int now=n-i-1;
            if(mp.find(y-x)!=mp.end()) {
                now+=mp[y-x];
                ans=min(ans,now);
            }
        }
        cout << ans << endl;
    }
}