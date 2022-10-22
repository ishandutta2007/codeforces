#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[100005];
    bool t[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    int ans = 0;
    for(int i = 0; i < n; i++) if(t[i]) ans += a[i];
    int s = 0;
    for(int i = 0; i < k; i++) if(!t[i]) s += a[i];
    int l = s;
    for(int i = k; i < n; i++){
        if(!t[i]) s += a[i];
        if(!t[i - k]) s -= a[i - k];
        l = max(l, s);
    }
    cout << ans + l << endl;
}