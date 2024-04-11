#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int a[200005];
int l[200005], r[200005], d[200005];
PP pp[200005];

int main()
{
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;
        pp[i] = PP(l[i], P(r[i], d[i]));
    }
    sort(pp, pp + k);
    pp[k] = PP(n + 1, P(n + 1, 100000000));
    int now = 262144;
    int mid = now / 2;
    while(mid){
        int nt = n + 1;
        int sq = 0;
        int key = 0;
        for(int i = 0; i <= k; i++){
            if(pp[i].second.second <= now) continue;     //d <= now mushi
            if(pp[i].first >= key){
                nt += (key - sq) * 2;
                sq = pp[i].first;
            }
            key = max(key, pp[i].second.first);
        }
        if(nt > t) now += mid;
        else now -= mid;
        mid /= 2;
    }
    if(now == 1){
        int nt = n + 1;
        int sq = 0;
        int key = 0;
        for(int i = 0; i <= k; i++){
            if(pp[i].second.second <= now) continue;     //d <= now mushi
            if(pp[i].first >= key){
                nt += (key - sq) * 2;
                sq = pp[i].first;
            }
            key = max(key, pp[i].second.first);
        }
        if(nt <= t) now--;
    }
    int nt = n + 1;
    int sq = 0;
    int key = 0;
    for(int i = 0; i <= k; i++){
        if(pp[i].second.second <= now) continue;     //d <= now mushi
        if(pp[i].first >= key){
            nt += (key - sq) * 2;
            sq = pp[i].first;
        }
        key = max(key, pp[i].second.first);
    }
    if(nt > t) now++;
    int ans = 0;
    for(int i = 0; i < m; i++) if(a[i] >= now) ans++;
    cout << ans << endl;
}