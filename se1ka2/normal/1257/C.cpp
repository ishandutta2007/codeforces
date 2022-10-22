#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int a[200005];
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int last[200005];
        fill(last, last + n + 1, -10000000);
        int ans = 1000000;
        for(int i = 0; i < n; i++){
            ans = min(ans, i - last[a[i]]);
            last[a[i]] = i;
        }
        if(ans == 1000000) cout << -1 << endl;
        else cout << ans + 1 << endl;
    }
}