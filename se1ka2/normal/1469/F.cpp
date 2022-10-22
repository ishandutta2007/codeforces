#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 400000;

bool ok(int mid, int n, int k, int *l){
    ll d[400005]{0};
    d[0] = 1;
    d[1] = -1;
    int i = 0;
    ll c = 1;
    for(int j = 0; j <= mid - 2; j++){
        d[j + 1] += d[j];
        for(; i < n; i++){
            if(d[j] == 0) break;
            if(l[i] <= 2) continue;
            int a = j + (l[i] + 2) / 2, b = j + (l[i] + 1) / 2;
            int x = l[i] / 2, y = (l[i] - 1) / 2;
            c += min(x, mid - j - 1) + min(y, mid - j - 1) - 1;
            d[j]--;
            d[j + 2] += 2;
            d[a + 1]--;
            d[b + 1]--;
        }
        if(i == n) break;
    }
    if(c >= k) return true;
    else return false;
}

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    int l[200005];
    for(int i = 0; i < n; i++) cin >> l[i];
    sort(l, l + n, greater<int>());
    int right = INF, left = 0;
    while(right - left > 1){
        int mid = (right + left) / 2;
        if(ok(mid, n, k, l)) right = mid;
        else left = mid;
    }
    if(right == INF) cout << -1 << endl;
    else cout << right << endl;
}