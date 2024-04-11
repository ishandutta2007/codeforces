#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1000000000000000000;

ll x[100005];
int a[100005], b[100005], c[100005], d[100005];
ll s[100005];
vector<P> v[100005], w[100005];
bool r[100005];
ll dp[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++){
            v[i].clear();
            w[i].clear();
        }
        for(int i = 0; i < n; i++) cin >> x[i];
        a[k + 1] = b[k + 1] = c[k + 1] = d[k + 1] = 0;
        w[0].push_back(P(0, k + 1));
        for(int i = 0; i < k; i++){
            cin >> a[i] >> b[i] >> c[i] >> d[i] >> s[i];
            a[i]--; b[i]--; c[i]--; d[i]--;
            v[a[i]].push_back(P(b[i], i));
            w[c[i]].push_back(P(d[i], i));
        }
        a[k] = c[k] = n - 1, b[k] = d[k] = m - 1;
        s[k] = 0;
        v[n - 1].push_back(P(b[k], k));
        for(int i = 0; i <= k; i++) r[i] = false;
        r[k + 1] = true;
        dp[k + 1] = 0;
        for(int h = 0; h < n; h++){
            if((int)v[h].size() == 0 || (int)w[h].size() == 0) continue;
            sort(v[h].begin(), v[h].end());
            sort(w[h].begin(), w[h].end());
            int k = v[h].size(), l = w[h].size();
            bool f;
            int i, j;
            ll t;
            f = false;
            i = 0, j = 0;
            t = INF;
            while(i < k){
                while(j < l && w[h][j].first <= v[h][i].first){
                    int e = w[h][j].second;
                    if(!r[e]){
                        j++;
                        continue;
                    }
                    t = min(t, dp[e] - x[h] * d[e]);
                    f = true;
                    j++;
                }
                if(!f){
                    i++;
                    continue;
                }
                int e = v[h][i].second;
                if(r[e] && dp[e] < t + x[h] * b[e] - s[e]){
                    i++;
                    continue;
                }
                dp[e] = t + x[h] * b[e] - s[e];
                r[e] = true;
                i++;
            }
            f = false;
            i = k - 1, j = l - 1;
            t = INF;
            while(i >= 0){
                while(j >= 0 && w[h][j].first >= v[h][i].first){
                    int e = w[h][j].second;
                    if(!r[e]){
                        j--;
                        continue;
                    }
                    t = min(t, dp[e] - x[h] * (m - 1 - d[e]));
                    f = true;
                    j--;
                }
                if(!f){
                    i--;
                    continue;
                }
                int e = v[h][i].second;
                if(r[e] && dp[e] < t + x[h] * (m - 1 - b[e]) - s[e]){
                    i--;
                    continue;
                }
                dp[e] = t + x[h] * (m - 1 - b[e]) - s[e];
                r[e] = true;
                i--;
            }
        }
        if(r[k]) cout << dp[k] << "\n";
        else cout << "NO ESCAPE\n";
    }
}