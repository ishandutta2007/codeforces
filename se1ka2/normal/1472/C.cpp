#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int d[200005];
        for(int i = n - 1; i >= 0; i--){
            if(i + a[i] >= n) d[i] = a[i];
            else d[i] = d[i + a[i]] + a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, d[i]);
        cout << ans << endl;
    }
}