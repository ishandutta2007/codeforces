#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;

int n, a[N];
bool vis[N];
vector<array<int, 2>> ins;

void get_cycle(int u, vector<int> &cycle){
    cycle.push_back(u);
    vis[u] = true;

    if(!vis[a[u]]) get_cycle(a[u], cycle);
}

void do_2_cycles(const vector<int> &c1, const vector<int> &c2){
    for(int i = 0; i < c2.size(); ++i)
        ins.push_back({c1[0], c2[i]});
    for(int i = 1; i < c1.size(); ++i)
        ins.push_back({c1[i], c2[0]});
    ins.push_back({c1[0], c2[0]});
}

void do_1_cycle(const vector<int> &cycle){
    if(cycle.size() == 2){
        int add;
        for(int i = 1; i <= n; ++i)
            if(cycle[0] != i && cycle[1] != i){
                add = i;
                break;
            }

        ins.push_back({cycle[0], add});
        ins.push_back({cycle[1], add});
        ins.push_back({cycle[0], add});
        return;
    }

    for(int i = 1; i < (int)cycle.size() - 1; ++i)
        ins.push_back({cycle[0], cycle[i]});
    ins.push_back({cycle[1], cycle.back()});
    ins.push_back({cycle[0], cycle.back()});
    ins.push_back({cycle[0], cycle[1]});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> prev_cycle;
    for(int i = 1; i <= n; ++i)
        if(!vis[i]){
            vector<int> cycle;
            get_cycle(i, cycle);
            if(cycle.size() == 1) continue;
            if(prev_cycle.empty()){
                prev_cycle = cycle;
                continue;
            }
            do_2_cycles(cycle, prev_cycle);
            prev_cycle = {};
        }

    if(prev_cycle.size()) do_1_cycle(prev_cycle);

    cout << ins.size() << "\n";
    for(auto [x, y]: ins)
        cout << x << " " << y << "\n";
}