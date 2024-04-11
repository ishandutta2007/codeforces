#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int w[100005];
        for(int i = 0; i < n; i++) cin >> w[i];
        int d[100005];
        for(int i = 0; i < n; i++) d[i] = 0;
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            d[u]++;
            d[v]++;
        }
        P p[100005];
        for(int i = 0; i < n; i++) p[i] = P(w[i], d[i] - 1);
        sort(p, p + n, greater<P>());
        ll ans = 0;
        for(int i = 0; i < n; i++) ans += w[i];
        cout << ans;
        int j = 0;
        for(int k = 2; k < n; k++){
            while(j < n && p[j].second == 0) j++;
            ans += p[j].first;
            p[j].second--;
            cout << " " << ans;
        }
        cout << "\n";
    }
}