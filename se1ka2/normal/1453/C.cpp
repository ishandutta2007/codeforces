#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[2005];
        for(int i = 0; i < n; i++) cin >> s[i];
        int r[10], l[10], u[10], d[10];
        for(int i = 0; i < 10; i++){
            r[i] = d[i] = -1;
            l[i] = u[i] = n;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = s[i][j] - '0';
                r[k] = max(r[k], j);
                l[k] = min(l[k], j);
                u[k] = min(u[k], i);
                d[k] = max(d[k], i);
            }
        }
        int ans[10]{0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k = s[i][j] - '0';
                int dx = max(i, n - 1 - i), dy = max(j, n - 1 - j);
                ans[k] = max(ans[k], max(dy * max(i - u[k], d[k] - i), dx * max(j - l[k], r[k] - j)));
            }
        }
        for(int i = 0; i < 10; i++) cout << ans[i] << " ";
        cout << endl;
    }
}