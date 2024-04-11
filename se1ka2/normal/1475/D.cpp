#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 100000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int k1 = 0, k2 = 0;
        ll a[200005];
        ll a1[200005], a2[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            int b;
            cin >> b;
            if(b == 1) a1[k1++] = a[i];
            else a2[k2++] = a[i];
        }
        sort(a1, a1 + k1, greater<ll>());
        sort(a2, a2 + k2, greater<ll>());
        int l1 = 0, l2 = 0;
        ll s = 0;
        int c = 0;
        int ans = INF;
        while(l1 < k1){
            s += a1[l1++];
            c++;
            if(s >= m){
                ans = c;
                break;
            }
        }
        while(true){
            while(s >= m){
                ans = min(ans, c);
                if(l1 == 0) break;
                s -= a1[--l1];
                c--;
            }
            if(s >= m) break;
            while(l2 < k2){
                s += a2[l2++];
                c += 2;
                if(s >= m){
                    ans = min(ans, c);
                    break;
                }
            }
            if(s < m) break;
        }
        if(ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}