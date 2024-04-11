#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cnt++; 
        else cnt--;
        if (cnt < 0) {
            puts("NO");
            return;
        }
    }
    if (s[n - 1] != 'B'){
        puts("NO");
        return;
    }
    puts("YES");
}
int main(){
    int t;
    cin >> t;
    while (t--) solve();
}