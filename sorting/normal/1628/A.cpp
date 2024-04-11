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

        vector<int> a(n);
        vector<vector<int>> pos(n + 2);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        for(int i = 0; i <= n; ++i)
            reverse(all(pos[i]));

        int mx = -1, prev_mx = -1;
        vector<int> ans;
        while(mx != n - 1){
            for(int i = 0; i <= n + 1; ++i){
                while(!pos[i].empty() && pos[i].back() <= prev_mx)
                    pos[i].pop_back();

                if(!pos[i].empty()){
                    check_max(mx, pos[i].back());
                    pos[i].pop_back();
                }
                else{
                    ans.push_back(i);
                    break;
                }
            }

            if(ans.back() == 0)
                ++mx;

            prev_mx = mx;
        }

        cout << ans.size() << "\n";
        for(int x: ans)
            cout << x << " ";
        cout << "\n";
    }
}