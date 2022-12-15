#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 3;

int n;
string a[N], b[N];
string s;

vector<int> adj[4 * N], rev_adj[4 * N];
bool ans[2 * N];

vector<int> order;
bool used[4 * N];
int timer, comp[4 * N];

void create_component(int u){
    used[u] = true;
    comp[u] = timer;

    for(int to: rev_adj[u]){
        if(used[to]) continue;
        create_component(to);
    }
}

void top_sort(int u){
    used[u] = true;

    for(int to: adj[u]){
        if(used[to]) continue;
        top_sort(to);
    }

    order.push_back(u);
}

bool do_2sat(){
    for(int i = 0; i < 4 * n; ++i)
        for(int to: adj[i])
            rev_adj[to].push_back(i);

    for(int i = 0; i < 4 * n; ++i)
        if(!used[i])
            top_sort(i);

    for(int i = 0; i < 4 * n; ++i)
        used[i] = false;

    timer = 0;
    for(int i = 4 * n - 1; i >= 0; --i){
        int u = order[i];
        if(!used[u]){
            timer++;
            create_component(u);
        }
    }
    
    for(int i = 0; i < 4 * n; i += 2)
        if(comp[i] == comp[i + 1])
            return false;

    for(int i = 0; i < 2 * n; ++i)
        used[i] = false;

    for(int u: order){
        if(used[u / 2]) continue;
        used[u / 2] = true;

        ans[u / 2] = (u & 1);
    }

    return true;
}

void create_graph(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int diff = (a[i][j] - '0') ^ (b[i][j] - '0');
            int r = (s[j] - '0'), c = (s[i] - '0');

            //cout << r << " " << c << " r c\n";

            if(!r && !c){
                if(diff){
                    cout << "-1\n";
                    exit(0);
                }
            }
            else if(r && !c){
                if(diff) adj[2 * i].push_back(2 * i + 1);
                else adj[2 * i + 1].push_back(2 * i);
            }
            else if(!r && c){
                if(diff) adj[2 * j + 2 * n].push_back(2 * j + 1 + 2 * n);
                else adj[2 * j + 2 * n + 1].push_back(2 * j + 2 * n);
            }
            else if(r && c){
                if(diff){
                    adj[2 * j + 2 * n].push_back(2 * i + 1);
                    adj[2 * i + 1].push_back(2 * j + 2 * n);
                    adj[2 * j + 1 + 2 * n].push_back(2 * i);
                    adj[2 * i].push_back(2 * j + 1 + 2 * n);
                }
                else{
                    adj[2 * j + 2 * n].push_back(2 * i);
                    adj[2 * i].push_back(2 * j + 2 * n);
                    adj[2 * j + 1 + 2 * n].push_back(2 * i + 1);
                    adj[2 * i + 1].push_back(2 * j + 1 + 2 * n);
                }
            }
        }
    }

    /*for(int i = 0; i < 4 * n; ++i){
        cout << i << ": ";
        for(int to: adj[i])
            cout << to << " ";
        cout << "\n";
    }*/
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    cin >> s;

    create_graph();
    
    if(!do_2sat()){
        cout << "-1\n";
        return 0;
    }

    vector<pair<string, int>> output;
    for(int i = 0; i < n; ++i)
        if(ans[i])
            output.push_back({"row", i});
    for(int i = 0; i < n; ++i)
        if(ans[i + n])
            output.push_back({"col", i});

    cout << output.size() << "\n";
    for(auto [str, i]: output)
        cout << str << " " << i << "\n";
}