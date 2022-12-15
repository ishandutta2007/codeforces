#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> p(n);
        for(int i = 0; i < n; ++i)
            cin >> p[i].first >> p[i].second;

        bool ok = false;
        for(int i = 0; i < n; ++i){
            bool curr = true;
            for(int j = 0; j < n; ++j)
                if(abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) > k)
                    curr = false;
            if(curr)
                ok = true;
        }

        cout << (ok ? 1 : -1) << "\n";
    }
}