#include <iostream>
using namespace std;
int n, a, b;
int x[102], y[102];

int main() {
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
    
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int s1, s2;

            s1 = x[i] + x[j];
            s2 = max(y[i], y[j]);

            if(max(s1, s2) <= max(a, b) && min(s1, s2) <= min(a, b)) {
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
            }   

            s1 = x[i] + y[j];
            s2 = max(x[j], y[i]);

            if(max(s1, s2) <= max(a, b) && min(s1, s2) <= min(a, b)) {
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
            }

            s1 = y[i] + y[j];
            s2 = max(x[j], x[i]);

            if(max(s1, s2) <= max(a, b) && min(s1, s2) <= min(a, b)) {
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
            }


            s1 = x[j] + y[i];
            s2 = max(x[i], y[j]);

            if(max(s1, s2) <= max(a, b) && min(s1, s2) <= min(a, b)) {
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
            }
        }
    }
    cout << ans << endl;
}