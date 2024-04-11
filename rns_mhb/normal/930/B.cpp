#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    for(char c = 'a'; c <= 'z'; c ++) {
        vector <int> v;
        int cnt[26];
        for(int i = 0; i < n; i ++) if(s[i] == c) v.push_back(i);
        int mx = 0;
        for(int i = 0; i < n; i ++) {
            memset(cnt, 0, sizeof cnt);
            for(int j = 0; j < v.size(); j ++) cnt[s[(i+v[j])%n]-'a'] ++;
            int gas = 0;
            for(int j = 0; j < v.size(); j ++) if(cnt[s[(i+v[j])%n]-'a'] == 1) gas ++;
            mx = max(mx, gas);
        }
        ans += mx;
    }
    printf("%.10lf\n", 1.0 * ans / n);
}