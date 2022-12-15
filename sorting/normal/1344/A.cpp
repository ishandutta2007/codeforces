#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] += i;
    }

    for(int i = 0; i < n; ++i){
        a[i] %= n;
        if(a[i] < 0)
            a[i] += n;
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n - 1; ++i){
        if(a[i] == a[i + 1]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}