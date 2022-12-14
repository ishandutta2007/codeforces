#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200005;
long long t, n, sum[N];
vector<long long> S[N];
struct Data{
    int x, y;
    bool operator < (Data &p) { return x>p.x || x==p.x && y<p.y; }
} a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i].y;
        for(int i=1; i<=n; ++i) cin >> a[i].x;
        sort(a+1, a+n+1);
        for(int i=1; i<=n; ++i) S[i].clear(), sum[i] = 0;
        for(int i=1; i<=n; ++i) {
            if (S[a[i].y].empty()) S[a[i].y].push_back(a[i].x);
            else S[a[i].y].push_back(S[a[i].y].back() + a[i].x);
        }
        for(int i=1; i<=n; ++i) {
            int SZ = S[i].size();
            for(int j=1; j<=SZ; ++j) sum[j] += S[i][SZ / j * j - 1];
        }
        for(int i=1; i<=n; ++i) cout << sum[i] << ' ';
        cout << '\n';
    }
}