#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 10000000000000;

int main()
{
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        ll t[100005], x[100005];
        t[0] = 0, x[0] = 0;
        for(int i = 1; i <= n; i++) cin >> t[i] >> x[i];
        t[n + 1] = INF;
        int last = 0, lastlast = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(t[i] - t[last] >= abs(x[last] - x[lastlast])){
                lastlast = last;
                last = i;
                if(t[i + 1] - t[i] >= abs(x[last] - x[lastlast])) ans++;
            }
            else{
                if(x[last] > x[lastlast]){
                    if(x[lastlast] + (t[i] - t[last]) <= x[i] && x[i] <= min(x[last], x[lastlast] + (t[i + 1] - t[last]))) ans++;
                }
                else{
                    if(x[lastlast] - (t[i] - t[last]) >= x[i] && x[i] >= max(x[last], x[lastlast] - (t[i + 1] - t[last]))) ans++;
                }
            }
        }
        cout << ans << endl;
    }
}