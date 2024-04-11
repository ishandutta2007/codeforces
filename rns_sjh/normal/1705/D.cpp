#include<bits/stdc++.h>
using namespace std;

#define N 200020

char s[N], t[N];
int gs[N], gt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tcase, n;
    for(cin >> tcase;tcase --;){
        cin >> n;
        cin >> s >> t;
        int cs = 0, ct = 0;
        gs[cs] = gt[ct] = 1;
        for(int i = 1;i < n;i ++){
            if(s[i] == s[i - 1]) gs[cs] ++;
            else gs[++ cs] = 1;
            if(t[i] == t[i - 1]) gt[ct] ++;
            else gt[++ ct] = 1;
        }
        if(s[0] != t[0] || s[n - 1] != t[n - 1] || ct != cs){
            cout << -1 << endl;
            continue;
        }
        long long ans = 0;
        for(int i = 0;i <= cs;i ++){
            int p = gt[i] - gs[i];
            gs[i + 1] -= p;
            ans += abs(p);
        }
        cout << ans << endl;
    }
    return 0;
}