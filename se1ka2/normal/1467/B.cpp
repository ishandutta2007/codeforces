#include <iostream>
using namespace std;

bool hc(int i, int *a, int n){
    if(i == 0 || i == n - 1) return false;
    if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1])) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[300005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int b[300005];
        for(int i = 0; i < n; i++) b[i] = a[i];
        bool d[300005];
        int s = 0;
        for(int i = 0; i < n; i++){
            d[i] = hc(i, a, n);
            s += d[i];
        }
        bool e[300005];
        for(int i = 0; i < n; i++) e[i] = d[i];
        int ans = s;
        for(int i = 1; i < n - 1; i++){
            b[i] = a[i - 1];
            for(int j = i - 1; j <= i + 1; j++) e[j] = hc(j, b, n);
            ans = min(ans, s + e[i - 1] + e[i] + e[i + 1] - d[i - 1] - d[i] - d[i + 1]);
            b[i] = a[i];
            for(int j = i - 1; j <= i + 1; j++) e[j] = d[j];
            b[i] = a[i + 1];
            for(int j = i - 1; j <= i + 1; j++) e[j] = hc(j, b, n);
            ans = min(ans, s + e[i - 1] + e[i] + e[i + 1] - d[i - 1] - d[i] - d[i + 1]);
            b[i] = a[i];
            for(int j = i - 1; j <= i + 1; j++) e[j] = d[j];
        }
        cout << ans << endl;
    }
}