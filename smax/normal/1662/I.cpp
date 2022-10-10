#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
// const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> ppl(n);
    vector<int> shop(m);
    for(int x=0;x<n;x++) {
        cin >> ppl[x];
    }
    for(int x=0;x<m;x++) {
        cin >> shop[x];
    }
    sort(shop.begin(),shop.end());
    vector<int> prefix(n+1,0);
    for(int x=1;x<=n;x++) {
        prefix[x] = prefix[x-1] + ppl[x-1];
    }

    int maxCount = prefix[min(max((shop[0]-1)/100,0LL)+1,n)];
    if(shop[0]==0) {
        maxCount = 0;
    }
    if(shop[m-1]<(n-1)*100) {
        maxCount = max(maxCount,prefix[n]-prefix[(shop[m-1]+1)/100+1]);
    }
    // cout << prefix[n] << endl;
    // cout << (shop[m-1]+1)/100 << endl;
    // cout << prefix[(shop[m-1]+1)/100] << endl;

    int prevShop = 0;
    for(int x=0;x<n;x++) {
        int loc = x*100;
        while(prevShop<m-1 && shop[prevShop+1]<=loc) {
            prevShop++;
        }
        if(shop[prevShop]==loc) {
            continue;
        }
        if(prevShop==m-1) {
            break;
        }

        int spot = min(loc*2-shop[prevShop],shop[prevShop+1]);
        // cout << spot << endl;
        maxCount = max(maxCount,prefix[min((spot+shop[prevShop+1]-1)/2/100+1,n)] - prefix[loc/100]);

        // cout << prefix[3]-prefix[2] <<



    }

    cout << maxCount << endl;


    return 0;
}