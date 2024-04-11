#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5 + 7;

int p[kN];

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> p[i];

    int curr = 1;
    for(int i = n; i >= 1; --i){
        int pos;
        for(int j = i; j >= 1; --j){
            if(curr == p[j]){
                pos = j;
                break;
            }

            if(p[j] != p[j - 1] + 1){
                cout << "No\n";
                return;
            }
        }

        curr = p[i] + 1;
        i = pos;
    }

    cout << "Yes\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}