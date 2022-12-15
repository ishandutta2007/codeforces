#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;

const int N = 2e5 + 3;
const int MAX = 2.5e6 + 3;

int n;
pair<int, int> a[N];
clock_t timer = clock();
mt19937 mt(23);

vector<pair<int, int>> mp[2 * MAX]; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    if(n <= 150){
        for(int x1 = 0; x1 < n; ++x1)
            for(int x2 = x1 + 1; x2 < n; ++x2)
                for(int x3 = x2 + 1; x3 < n; ++x3)
                    for(int x4 = x3 + 1; x4 < n; ++x4){
                        if(a[x1].first + a[x4].first == a[x2].first + a[x3].first){
                            cout << "YES\n";
                            cout << a[x1].second + 1 << " " << a[x4].second + 1 << " " << a[x2].second + 1 << " " << a[x3].second + 1 << "\n";
                            return 0;
                        }
                    }
        cout << "NO\n";
        return 0;
    }

    while(((float)clock() - timer) / (float)CLOCKS_PER_SEC <= 1.5){
        int x = mt() % n;
        int y = mt() % n;
        if(x == y) continue; 
    
        int sum = a[x].first + a[y].first;
        for(auto [x2, y2]: mp[sum]){
            if(x2 != x && x2 != y && y2 != x && y2 != y){
                cout << "YES\n";
                cout << a[x].second + 1 << " " << a[y].second + 1 << " " << a[x2].second + 1 << " " << a[y2].second + 1 << "\n";
                return 0;
            }
        }
        mp[sum].push_back({x, y});
    }

    cout << "NO\n";
}