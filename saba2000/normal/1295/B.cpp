#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009];
int p[200009];
int f[200009];
void solve(){
    int n, x;
    cin >> n >> x;
    string s;

    cin >> s;
    for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') a[i+1] = -1;
            else a[i+1] = 1;

        }
            int fl = 0;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + a[i];
        if(p[i] == x) fl = 1;
    }
    if(p[n] == 0 && fl){
        cout<<-1<<endl;
                return ;
    }

    int ans  = 0;
    for(int i = 0; i < n; i++){
        if(p[n] == 0){
            if(p[i] == x) ans++;
            continue;
        }
        if((p[i] - x) % p[n]) continue;
        if(p[i] > x && p[n] > 0) continue;
        if(p[i] < x && p[n] < 0) continue;
        ans++;

    }
    for(int i = 0; i <= 2*n; i++)
        f[i] = 0, a[i] = 0, p[i] = 0;
    cout<<ans<<endl;
}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}