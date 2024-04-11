#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
vector<int> back[MAXN];
int perm[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            perm[i] = -1;
            back[i].clear();
        }
        back[n + 1].clear();
        bool bad = false;
        stack<int> s;
        for(int i = 1; i <= n; i++) {
            if(v[i] == -1) continue;
            while(!s.empty() && i >= s.top())
                s.pop();
            if(!s.empty() && v[i] > s.top()) {
                bad = true;
                break;
            }
            s.push(v[i]);
            back[v[i]].push_back(i);
        }
        if(bad) {
            cout << "-1\n";
            continue;
        }
        int ct = n;
        for(int i = n + 1; i >= 1; i--) {
            if(back[i].empty())
                continue;
            if(i <= n && perm[i] == -1) {
                perm[i] = ct;
                ct--;
            }
            for(auto x : back[i]) {
                perm[x] = ct;
                ct--;
            }
        }
        for(int i = 1; i <= n; i++)
            if(perm[i] == -1) perm[i] = ct--;
        for(int i = 1; i <= n; i++)
            cout << perm[i] << " ";
        cout << '\n';
    }    
}