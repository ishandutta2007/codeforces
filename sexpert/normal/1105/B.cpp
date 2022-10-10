    #include <bits/stdc++.h>
    using namespace std;
     
    int ct[26];
     
    int main() {
        int n, k;
        string s;
        cin >> n >> k >> s;
        s += '*';
        int sf = 1;
        for(int i = 0; i < s.length() - 1; i++) {
            if(sf == k || s[i] != s[i + 1]) {
                if(sf == k)
                    ct[s[i] - 'a']++;
                sf = 1;
            }
            else if(s[i] == s[i + 1])
                sf++;
        }
        int mx = -1;
        for(int i = 0; i < 26; i++)
            mx = max(mx, ct[i]);
        cout << mx << endl;
    }