    #include <bits/stdc++.h>
    using namespace std;
     
    const int MAXN = 1e6 + 2;
     
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum[MAXN];
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + (s[i - 1] == '(' ? 1 : -1);
        if(sum[n] != 2 && sum[n] != -2) {
            cout << 0 << endl;
            return 0;
        }
        int ct = 0;
        if(sum[n] == 2) {
            for(int i = n; i >= 1; i--) {
                if(sum[i] < 0) {
                    cout << 0 << endl;
                    return 0;
                }
            }
            for(int i = n; i >= 1; i--) {
                if(sum[i] < 2)
                    break;
                if(s[i - 1] == '(')
                    ct++;
            }
        }
        else {
            for(int i = 1; i <= n; i++) {
                if(sum[i] < -2) {
                    cout << 0 << endl;
                    return 0;
                }
            }
            int k;
            for(int i = 1; i <= n; i++) {
                if(sum[i] < 0) {
                    k = i;
                    break;
                }
            }
            for(int i = 1; i <= k; i++) {
                if(s[i - 1] == ')')
                    ct++;
            }
        }
        cout << ct << endl;
    }