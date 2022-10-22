#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    P p[200005];
    for(int i = 0; i < n; i++) p[i] = P(a[i], i);
    sort(p, p + n, greater<P>());
    int l[31];
    l[0] = 1;
    for(int i = 1; i <= 30; i++) l[i] = l[i - 1] * 2;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int u = p[i].second;
        int r = *upper_bound(l, l + 31, a[u]);
        if(u < n - 2){
            int s = 0;
            for(int j = u + 1; j < n - 1; j++){
                s += a[j];
                if(s >= r) break;
                if(a[j + 1] <= a[u] && s == (a[u] ^ a[j + 1])) ans++;
            }
        }
        if(u > 1){
            int s = 0;
            for(int j = u - 1; j > 0; j--){
                s += a[j];
                if(s >= r) break;
                if(a[j - 1] < a[u] && s == (a[u] ^ a[j - 1])) ans++;
            }
        }
    }
    cout << ans << "\n";
}