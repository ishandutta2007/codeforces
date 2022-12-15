#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 3;

int n, k, ans = 0;
pair<int, int> p[N];
bool vis[N];

int query(const vector<int> &v){
    cout << "? ";
    for(int x: v)
        cout << x + 1 << " ";
    cout << "\n";
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

void answer(int x){
    cout << "! " << x << "\n";
    cout.flush();
    exit(0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    queue<int> q;
    q.push(0);
    vis[0] = true;
    p[0] = {-1, -1};

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == n){
            vector<pair<int, int>> v;
            int t = -1;
            while(x != 0){
                v.push_back({x, t});
                t = p[x].second;
                x = p[x].first;
            }
            v.push_back({0, t});
            reverse(v.begin(), v.end());
            v.pop_back();

            bool odd[N];
            fill(odd, odd + n, false);
            for(auto [x, a]: v){
                int b = k - a;
                vector<int> quer;
                for(int i = 0; i < n; ++i){
                    if(odd[i] && a){
                        quer.push_back(i);
                        --a;
                        odd[i] = !odd[i];
                    }
                    else if(!odd[i] && b){
                        quer.push_back(i);
                        --b;
                        odd[i] = !odd[i];
                    }
                }
                ans ^= query(quer);
            }
            answer(ans);
            return 0;
        }

        for(int a = max(0, x + k - n); a <= min(x, k); ++a){
            int to = x + k - 2 * a;
            if(!vis[to]){
                q.push(to);
                vis[to] = true;
                p[to] = {x, a};
            }
        }
    }

    cout << "-1\n";
    cout.flush();
    return 0;
}