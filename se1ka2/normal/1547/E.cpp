#include <iostream>
#include <vector>
using namespace std;

const int INF = 2000000000;

int main()
{
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        int a[300005], t[300005];
        for(int i = 0; i < k; i++){
            cin >> a[i];
            a[i]--;
        }
        for(int i = 0; i < k; i++) cin >> t[i];
        int b[300005];
        for(int i = 0; i < n; i++) b[i] = INF;
        for(int i = 0; i < k; i++) b[a[i]] = t[i];
        int ans[300005];
        for(int i = 0; i < n; i++) ans[i] = INF;
        int r = INF;
        for(int i = 0; i < n; i++){
            r = min(r + 1, b[i]);
            ans[i] = min(ans[i], r);
        }
        r = INF;
        for(int i = n - 1; i >= 0; i--){
            r = min(r + 1, b[i]);
            ans[i] = min(ans[i], r);
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}