#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e6 + 500;
int a[N];
int n;
ll ans, x, y;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    x = -a[0], y = a[0];
    for(int i = 0; i < n; i++){
        ans = max(x + a[i], y - a[i]);
        x = max(x, ans - a[i+1]);
        y = max(y, ans + a[i+1]);
    }
    cout << ans << endl;
}