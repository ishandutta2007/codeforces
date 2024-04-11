#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 100;

int N, M;
vector<int> lit[MAXN];
vector<pair<int, int>> app[MAXN];

int RUNS = 1;
int done[MAXN];
int when[MAXN];
bool ans[MAXN];

void sat(int c, int v) { // use variable v to satisfy clause c
    done[c] = RUNS;
    when[v] = RUNS;    
    for (int i = 0; i < app[v].size(); i++) 
        if(app[v][i].first == c)
            ans[v] = app[v][i].second;
}

int oth(int c, int v) {
    if(app[v].size() < 2) return -1;
    return app[v][0].first + app[v][1].first - c;
}

int back = -1;

bool dfs(int loc) {
    bool below = false;

    for (int var : lit[loc]) {
        int nbr = oth(loc, var);
        if(when[var] == RUNS) continue; // ignore the edge back to the parent
        if(done[nbr]) {
            if(back == -1 && done[nbr] == RUNS) {
                back = nbr;
                sat(nbr, var);
            }
            continue;
        }
        sat(nbr, var);
        if(dfs(nbr)) {
            below = true;
            sat(loc, var);
        }
    }

    return below || loc == back;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        lit[i].resize(K);

        for (int j = 0; j < K; j++) {
            int var;
            cin >> var;
            
            int mul = var < 0 ? 0 : 1;
            if(var < 0) var = -var;

            lit[i][j] = var - 1;
            app[var-1].emplace_back(i, mul);
        }
    }

    queue<pair<int, int>> simple;

    for (int v = 0; v < M; v++) {
        if(app[v].size() < 2 || app[v][0].second == app[v][1].second)
            for (int a = 0; a < app[v].size(); a++)
               simple.push({ app[v][a].first, v }); 

        while(simple.size()) {
            pair<int, int> todo = simple.front(); simple.pop();            
            if(done[todo.first]) continue;

            sat(todo.first, todo.second);

            for (int var : lit[todo.first]) {
                int lit = oth(todo.first, var);
                if(lit != -1 && app[var][0].second != app[var][1].second && !done[lit])
                    simple.push({ lit, var });
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if(done[i]) continue;
        RUNS++, back = -1;
        done[i] = RUNS;
        dfs(i);
        if(back == -1) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < M; i++) {
        cout << ans[i];
    }
    cout << endl;
}