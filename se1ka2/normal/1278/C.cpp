#include <iostream>
#include <vector>
using namespace std;
const int INF = 10000000;

int main()
{
    int t;
    cin >> t;
    int a[200004];
    int d[100004];
    int e[100004];
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int s = 0;
        for(int i = 0; i < n * 2; i++){
            cin >> a[i];
            if(a[i] == 1) s++;
            else s--;
        }
        if(s < 0){
            for(int i = 0; i < n * 2; i++) a[i] = 3 - a[i];
            s = -s;
        }
        int l = 0;
        for(int i = 0; i <= n; i++) d[i] = INF;
        for(int i = 0; i <= n; i++) e[i] = INF;
        d[0] = e[0] = 0;
        for(int i = 1; i <= n; i++){
            if(a[n - i] == 1) l++;
            else l--;
            if(l) if(d[l] == INF) d[l] = i;
        }
        l = 0;
        for(int i = 1; i <= n; i++){
            if(a[n + i - 1] == 1) l++;
            else l--;
            if(l) if(e[l] == INF) e[l] = i;
        }
        int ans = INF;
        for(int i = 0; i <= s; i++) if(i <= n && s - i <= n) ans = min(ans, d[i] + e[s - i]);
        cout << ans << endl;
    }
}