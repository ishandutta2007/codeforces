#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2050;
const ll INF = (ll)1e18;

int n,m;
int a[N], b[N];
ll ma[N], mb[N];
ll x;

int main(){
    fill(ma, ma+N, INF);
    fill(mb, mb+N, INF);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    cin >> x;
    for(int i = 0; i < n; i++){
        ll cur = 0;
        for(int j = i; j < n; j++){
            cur += a[j];
            ma[j - i + 1] = min(ma[j - i + 1], cur);
        }
    }
    for(int i = 0; i < m; i++){
        ll cur = 0;
        for(int j = i; j < m; j++){
            cur += b[j];
            mb[j - i + 1] = min(mb[j - i + 1], cur);
        }
    }
//    for(int i = 1; i <= n; i++) cout << ma[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= m; i++) cout << mb[i] << " ";
//    cout << endl;
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(ma[i] * mb[j] <= x) res = max(res, i * j);
        }
    }
    cout << res << endl;

}