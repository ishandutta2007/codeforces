#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int k;
        cin >> k;
        string s, a, b;
        cin >> s >> a >> b;
        int temp[26], final[26], fixed[26], n = s.length();
        memset(temp, -1, sizeof(temp));
        memset(final, -1, sizeof(final));
        memset(fixed, 0, sizeof(fixed));
        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if(temp[x] == -1) {
                int p = k - 1;
                for(;p >= 0; p--) {
                    if(!fixed[p])
                        break;
                }
                temp[x] = p;
                fixed[p] = 1;
            }
        }
        memset(fixed, 0, sizeof(fixed));
        int coin = 0;
        for(int i = 0; i < n; i++) {
            bool temFound = false;
            int x = s[i] - 'a', y;
            // Template value has already been determined
            if(final[x] != -1) {
                y = final[x];
                temFound = true;
            }
            else
                y = temp[x];
            // Too small, die and find max coincidence
            if(y < a[i] - 'a') {
                break;
            }
            // Larger and can't fix for some reason.
            if(y > a[i] - 'a' && (temFound || fixed[a[i] - 'a'])) {
                coin = i;
                break;
            }
            // Try to match
            if(!temFound) {
                if(y > a[i] - 'a')
                    coin = i;
                final[x] = a[i] - 'a';
                fixed[a[i] - 'a'] = 1;
                for(int c = 0; c < k; c++) {
                    // Update to new values
                    if(c == x)
                        continue;
                    if(temp[c] >= final[x]) {
                        int tfm = temp[c] + 1;
                        while(fixed[tfm])
                            tfm++;
                        temp[c] = tfm;
                    }
                }
            }
            if(i == n - 1)
                coin = n;
        }
        // coin = first coin characters coincide.
        // t = string after transforms
        memset(temp, -1, sizeof(temp));
        memset(fixed, 0, sizeof(fixed));
        string t = "";
        for(int i = 0; i < coin; i++) {
            t += 'a' + (final[s[i] - 'a']);
            fixed[final[s[i] - 'a']] = 1;
            temp[s[i] - 'a'] = final[s[i] - 'a'];
        }
        if(coin < n) {
            if(a[coin] - 'a' == k - 1) {
                cout << "NO\n";
                continue;
            }
            for(int c = a[coin] - 'a' + 1; c < k; c++) {
                if(temp[s[coin] - 'a'] != -1)
                    break;
                if(fixed[c])
                    continue;
                temp[s[coin] - 'a'] = c;
                fixed[c] = 1;
                break;
            }
            t += 'a' + temp[s[coin] - 'a'];
        }
        for(int i = coin + 1; i < n; i++) {
            // Just copy known value
            if(temp[s[i] - 'a'] != -1) {
                t += 'a' + temp[s[i] - 'a'];
                continue;
            }
            // Assign smallest value
            for(int c = 0; c < k; c++) {
                if(fixed[c])
                    continue;
                temp[s[i] - 'a'] = c;
                fixed[c] = 1;
                break;
            }
            t += 'a' + temp[s[i] - 'a'];
        }
        if(t > b) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
            for(int c = 0; c < k; c++) {
                if(temp[c] == -1) {
                    for(int d = 0; d < k; d++) {
                        if(fixed[d])
                            continue;
                        temp[c] = d;
                        fixed[d] = 1;
                        break;
                    }
                }
            }
            for(int c = 0; c < k; c++)
                cout << (char)('a' + temp[c]);
            cout << endl;
        }
    }    
}