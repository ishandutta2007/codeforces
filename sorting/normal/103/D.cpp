#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3e5 + 3;
const int T = 550;

ll w[N], a[N], ans[N];
int n, p;
pair<int, int> q[N];
vector<pair<int, int>> v[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> w[i];

    cin >> p;
    for(int i = 1; i <= p; ++i){
        cin >> q[i].first >> q[i].second;
        v[q[i].second].push_back({q[i].first, i});
    }

    for(int i = 1; i <= T; ++i){
        if(v[i].empty()) continue;

        for(int j = n; j >= 1; --j){
            if(j + i > n){
                a[j] = w[j];
                continue;
            }
            a[j] = w[j] + a[j + i];
        }

        for(auto [start, idx]: v[i])
            ans[idx] = a[start];
    }

    for(int i = T + 1; i < N; ++i){
        if(v[i].empty()) continue;
        for(auto [start, idx]: v[i]){
            ans[idx] = 0;
            while(start <= n){
                ans[idx] += w[start];
                start += i;
            }
        }
    }

    for(int i = 1; i <= p; ++i)
        cout << ans[i] << "\n";
}