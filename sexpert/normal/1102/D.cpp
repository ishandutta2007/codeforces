    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        int n;
        string s;
        cin >> n >> s;
        int ct0 = 0, ct1 = 0, ct2 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0')
                ct0++;
            if(s[i] == '1')
                ct1++;
            if(s[i] == '2')
                ct2++;
        }
     
        for(int i = 0; i < n; i++) {
            if(ct2 <= n/3)
                break;
            if(s[i] == '2') {
                ct2--;
                if(ct0 < n/3) {
                    ct0++;
                    s[i] = '0';
                }
                else {
                    ct1++;
                    s[i] = '1';
                }
            }
        }
     
        for(int i = 0; i < n; i++) {
            if(ct1 <= n/3)
                break;
            if(s[i] == '1' && ct0 < n / 3) {
                ct1--;
                ct0++;
                s[i] = '0';
            }
        }
     
        for(int i = n - 1; i >= 0; i--) {
            if(ct1 <= n/3 || ct2 == n / 3)
                break;
            if(s[i] == '1') {
                ct1--;
                ct2++;
                s[i] = '2';
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(ct0 <= n/3)
                break;
            if(s[i] == '0') {
                ct0--;
                if(ct2 < n/3) {
                    ct2++;
                    s[i] = '2';
                }
                else {
                    ct1++;
                    s[i] = '1';
                }
            }
        }
        cout << s << endl;
    }