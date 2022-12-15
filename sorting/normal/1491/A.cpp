#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int cnt[2]{0, 0};
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 0; i < q; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int pos;
            cin >> pos;
            a[pos] = !a[pos];
            cnt[a[pos]]++;
            cnt[!a[pos]]--;
        }
        else{
            int k;
            cin >> k;

            if(cnt[1] >= k) cout << "1\n";
            else cout << "0\n";
        }
    }
}