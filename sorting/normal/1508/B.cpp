#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k;

bool bigger(int n, ll k){
    if(n >= 61) return true;
    if(n == 0) return 1 >= k;
    return (1ll << (n - 1)) >= k;
}

void solve(){
    cin >> n >> k;
    if(!bigger(n, k)){
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    int i = 1;
    while(i <= n){
        for(int j = i; j <= n; ++j){
            if(bigger(n - j, k)){
                for(int i1 = j; i1 >= i; --i1)
                    ans.push_back(i1);
                i = j + 1;
                break;
            }
            k -= (1ll << (n - j - 1));
        }
    }

    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}