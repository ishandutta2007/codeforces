#include <bits/stdc++.h>

using namespace std;

const int k_N = 1000 + 3;

int n;
vector<pair<int, int>> inv;
int a[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(a[i] > a[j])
                inv.push_back({i, j});

    sort(inv.begin(), inv.end(), [](pair<int, int> l, pair<int, int> r){
        if(l.second != r.second)
            return l.second > r.second;
        if(a[l.first] != a[r.first])
            return a[l.first] < a[r.first];
        return l.first < r.first;
    });

    cout << inv.size() << "\n";
    for(auto [f, s]: inv){
        cout << f << " " << s << "\n";
    }
}