#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1000000009;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int N, M;
        cin >> N >> M;
        int nn[2]{0}, mm[2]{0};
        int aa[2][200005], bb[2][200005];
        for(int i = 0; i < N; i++){
            int c;
            cin >> c;
            if(c < 0) aa[0][nn[0]++] = -c;
            else aa[1][nn[1]++] = c;
        }
        for(int i = 0; i < M; i++){
            int c;
            cin >> c;
            if(c < 0) bb[0][mm[0]++] = -c;
            else bb[1][mm[1]++] = c;
        }
        reverse(aa[0], aa[0] + nn[0]);
        reverse(bb[0], bb[0] + mm[0]);
        int ans = 0;
        for(int p = 0; p < 2; p++){
            int n = nn[p], m = mm[p];
            int a[200005], b[200005];
            for(int i = 0; i < n; i++) a[i] = aa[p][i];
            for(int i = 0; i < m; i++) b[i] = bb[p][i];
            a[n] = INF;
            b[m] = INF;
            int r[200005];
            r[m] = 0;
            for(int i = m - 1; i >= 0; i--){
                r[i] = r[i + 1];
                if(b[i] == *lower_bound(a, a + n, b[i])) r[i]++;
            }
            int s = 0;
            for(int i = 0; i < m; i++){
                int u = upper_bound(a, a + n, b[i]) - a;
                int v = b + i - upper_bound(b, b + m, b[i] - u) + 1;
                s = max(s, r[i + 1] + v);
            }
            ans += s;
        }
        cout << ans << endl;
    }
}