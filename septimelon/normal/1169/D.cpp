#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long ans = 0;
    string s;
    cin >> s;
    long long m;
    m = s.size();
    //cout << s << " " << m << endl;
    if (m >= 9)
        ans = (m-8) * (m-7) / 2;
    bool it;
    int k;
    for (int l = 0; l <= m-3; l++) {
        for (int r = l+2; r < l+8 && r < m; r++) {
            it = false;
            for (int len = 1; 2*len <= r-l; len++) {
                k = l;
                while (k+2*len <= r) {
                    if (s[k] == s[k+len] && s[k] == s[k+2*len]) {
                        it = true;
                        break;
                    }
                    k++;
                }
                if (it) {
                        //cout << l << " " << r << endl;
                    ans++;
                    break;
                }
            }
        }
    }
    /*for (int i = 0; i <= m-9; i++) {
        if (s[i] == s[i+1] && s[i] == s[i+2]) {
            ans += 6;
        }
        else if (s[i] == s[i+2] && s[i] == s[i+4]) {
            ans += 4;
        }
        else if (s[i] == s[i+3] && s[i] == s[i+6]) {
            ans += 2;
        }
    }
    //cout << ans << endl;
    int k;
    for (int i = m-3; i > m-9 && i >= 0; i--) {
        k = 1;
        while (i+2*k < m) {
            if (s[i] == s[i+k] && s[i] == s[i+2*k]) {
                ans += (m - (i+2*k));
                break;
            }
            k++;
        }
    }*/
    cout << ans << endl;
    return 0;
}