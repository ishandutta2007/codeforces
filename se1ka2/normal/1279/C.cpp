#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n, m;
        cin >> n >> m;
        int a[100002], b[100002];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
            b[i]--;
        }
        ll d = 0;
        bool used[100002];
        for(int i = 0; i < n; i++) used[i] = false;
        ll ans = 0;
        for(ll i = 0; i < m; i++){
            if(used[b[i]]) ans++;
            else{
                for(; d < n; d++){
                    used[a[d]] = true;
                    if(a[d] == b[i]){
                        ans += d * 2 + 1 - i * 2;
                        d++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}