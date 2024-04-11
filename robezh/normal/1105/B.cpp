#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;
string s;
int scnt[128];

int main() {
    cin >> n >> k;
    cin >> s;
    char c = ' ';
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != c) {
            if(cnt >= k) scnt[c] ++;
            cnt = 1; c = s[i];
        }
        else {
            if(cnt == k) {
                scnt[c] ++;
                cnt = 1;
            }
            else cnt++;
        }
    }
    if(cnt >= k) scnt[c] ++;
    int res = 0;
    for(char ch = 'a'; ch <= 'z'; ch++) {
        res = max(scnt[ch], res);
    }
    cout << res << endl;

}