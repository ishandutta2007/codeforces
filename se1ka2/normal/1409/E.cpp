#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int x[200005], y[200005];
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> y[i];
        sort(x, x + n);
        x[n] = x[n - 1] + k + 1;
        int c[200005];
        int l[200005];
        for(int i = 0; i < n; i++) l[i] = 0;
        int j = 0;
        for(int i = 0; i <= n; i++){
            if(i > 0) l[i] = l[i - 1];
            while(x[i] - x[j] > k){
                c[j] = i - j;
                l[i] = max(l[i], c[j]);
                j++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, c[i] + l[i]);
        cout << ans << endl;
    }
}