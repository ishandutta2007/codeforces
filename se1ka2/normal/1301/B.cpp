#include <iostream>
using namespace std;

const int INF = 1000000007;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int n;
        cin >> n;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int s = INF, l = -INF;
        for(int i = 0; i < n; i++){
            if(a[i] == -1){
                if(i > 0 && a[i - 1] != -1){
                    s = min(s, a[i - 1]);
                    l = max(l, a[i - 1]);
                }
                if(i < n - 1 && a[i + 1] != -1){
                    s = min(s, a[i + 1]);
                    l = max(l, a[i + 1]);
                }
            }
        }
        int k = (l + s) / 2;
        for(int i = 0; i < n; i++) if(a[i] == -1) a[i] = k;
        int ans = 0;
        for(int i = 1; i < n; i++) ans = max(ans, abs(a[i] - a[i - 1]));
        cout << ans << " " << k << endl;
    }
}