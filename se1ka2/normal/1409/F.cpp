#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    int l = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != t[0] && s[i] != t[1]) l++;
    }
    if(t[0] == t[1]){
        int m = n - max(0, l - k);
        cout << m * (m - 1) / 2 << endl;
        return 0;
    }
    int ans = 0;
    for(int c = 0; c <= min(k, l); c++){
        for(int d = 0; d <= c; d++){
            string u = s;
            int j = 0;
            for(int i = 0; i < n; i++){
                if(j == d) break;
                if(u[i] != t[0] && u[i] != t[1]){
                    u[i] = t[0];
                    j++;
                }
            }
            for(int i = n - 1; i >= 0; i--){
                if(j == c) break;
                if(u[i] != t[0] && u[i] != t[1]){
                    u[i] = t[1];
                    j++;
                }
            }
            for(int e = 0; e <= min(k - c, n - l); e++){
                string v = u;
                int j = 0;
                int r = -1;
                for(int i = 0; i < n; i++){
                    if(j == e){
                        r = i - 1;
                        break;
                    }
                    if(v[i] == t[1]){
                        v[i] = '0';
                        j++;
                    }
                }
                for(int i = n - 1; i >= 0; i--){
                    if(j == min(k - c, n - l)) break;
                    if(i == r) break;
                    if(v[i] == t[0]){
                        v[i] = '1';
                        j++;
                    }
                }
                int a = 0, x = 0;
                for(int i = 0; i < n; i++){
                    if(v[i] == t[0] || v[i] == '0') a++;
                    if(v[i] == t[1] || v[i] == '1') x += a;
                }
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;
}