#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[300005];
    ll sa = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        sa += a[i];
    }
    int m;
    cin >> m;
    ll b[300005];
    ll sb = 0;
    for(int i = 0; i < m; i++){
        scanf("%lld", &b[i]);
        sb += b[i];
    }
    if(sa != sb){
        cout << -1 << endl;
        return 0;
    }
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        sa -= a[i];
        sb -= b[j];
        i++;
        j++;
        while(sa != sb){
            if(sa > sb){
                sa -= a[i];
                i++;
            }
            else{
                sb -= b[j];
                j++;
            }
        }
        ans++;
    }
    cout << ans << endl;
}