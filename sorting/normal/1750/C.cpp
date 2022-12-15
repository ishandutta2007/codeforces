#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;       

        vector<int> c(n);
        for(int i = 0; i < n; ++i){
            int ai = a[i] - '0';
            int bi = b[i] - '0';

            c[i] = ai ^ bi;
        }

        bool ok = true;
        for(int i = 0; i < n - 1; ++i){
            if(c[i] != c[i + 1]){
                ok = false;
            }
        }

        if(!ok){
            cout << "NO\n";
            continue;
        }

        vector<pair<int, int>> ans;
        if(c[0]){
            ans.push_back({1, n});
            for(int i = 0; i < n; ++i)
                a[i] = (1 - (a[i] - '0')) + '0';
        }

        vector<int> av(n);
        for(int i = 0; i < n; ++i)
            av[i] = a[i] - '0';

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(av[i] == 0){
                if(cnt){
                    ans.push_back({i - cnt + 1, i + 1});
                    ans.push_back({i + 1, i + 1});
                }
                cnt = 0;
            }
            else ++cnt;
        }

        if(cnt){
            if(cnt == n){
                ans.push_back({1, n - 1});
                ans.push_back({n, n});
            }
            else{
                ans.push_back({n - cnt, n});
                ans.push_back({n - cnt, n - cnt});
            }
        }

        cout << "YES\n";
        cout << ans.size() << "\n";
        for(auto [l, r]: ans)
            cout << l << " " << r << "\n";
    }
}