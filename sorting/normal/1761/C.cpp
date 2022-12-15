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

        vector<string> b(n);
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        vector<vector<int>> adj(n);
        vector<int> cnt(n, 0);
        vector<set<int>> ans(n);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(b[i][j] == '1'){
                    adj[i].push_back(j);
                    cnt[j]++;
                }

        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(!cnt[i]){
                q.push(i);
                cnt[i] = 1;
            }

        while(!q.empty()){
            int x = q.front();
            q.pop();

            ans[x].insert(x);

            for(int to: adj[x]){
                for(int u: ans[x])
                    ans[to].insert(u);

                --cnt[to];
                if(!cnt[to]){
                    q.push(to);
                    cnt[to] = 1;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            cout << ans[i].size() << " ";
            for(int u: ans[i])
                cout << u + 1 << " ";
            cout << "\n";
        }
    }
}