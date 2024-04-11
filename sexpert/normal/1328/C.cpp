        #include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;
         
        void solve() {
            int n;
            cin >> n;
            string s, t;
            string bs;
            cin >> bs;
            int p = 0;
            for(; p < n; p++) {
                if(bs[p] == '2') {
                    s += '1';
                    t += '1';
                }
                if(bs[p] == '0') {
                    s += '0';
                    t += '0';
                }
                if(bs[p] == '1')
                    break;
            }
            if(p < n) {
                s += '1';
                t += '0';
                p++;
                for(; p < n; p++) {
                    s += '0';
                    t += bs[p];
                }
            }
            cout << s << '\n' << t << '\n';
        }
         
        int main() {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            
            int t;
            cin >> t;
            while(t--)
                solve();
        }