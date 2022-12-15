#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;

int n, a[k_N], b[k_N];

void solve(){
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    b[1] = a[1];
    for(int i = 2; i <= n; ++i)
        b[i] = max(b[i - 1], a[i]);

    int answer = 0;
    for(int i = 1; i <= n; ++i){
        if(!(b[i] - a[i]))
            continue;

        for(int bit = 0; true; ++bit){
            if((1ll << bit) > (b[i] - a[i])){
                answer = max(answer, bit);
                break;
            }
        }
    }

    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}