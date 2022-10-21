#include<cstdio>
#include<iostream>
#include<vector>
#include <map>
#include <regex>

using namespace std;

const int N = 3500, INF = (int)1e9;
const int M = 32000;

struct edge{
    int to, cap, rev;
    edge(int _to, int _cap, int _rev){
        to = _to, cap = _cap, rev = _rev;
    }
};

int n,m,a,b;
int id = 0;
vector<edge> G[N];
map<int, int> mp[120];
bool used[N];
int p[M];
int num[N];
vector<int> pms;

void add_edge(int from, int to, int cap){
    //cout << "adding " << from << ", " << to << ", " << cap << endl;
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f){
    if(v == t) return f;
    used[v] = true;

    for(int i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int f = 0;
    for(;;){
        fill(used, used + N, false);
        int d = dfs(s, t, INF);
        if(d == 0) return f;
        f += d;
    }
}

void setup_primes(){
    for(int i = 0; i < M; i++) p[i] = i;
    for(int i = 2; i < M; i++){
        if(p[i] != i) continue;
        pms.push_back(i);
        for(int j = i * 2; j < M; j += i) p[j] = i;
    }
}

int get_id(int i, int x){
    if(mp[i].count(x)) return mp[i][x];
    else return mp[i][x] = id++;
}

int main(){
    setup_primes();
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> num[i];
    id = n;
    int s = id++, t = id++;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) add_edge(s, i, INF);
        else add_edge(i, t, INF);
    }

    for(int i = 0; i < n; i++){
        int cur = num[i];
        for(int pm : pms){
            int cnt = 0;
            while(cur % pm == 0){cnt++, cur /= pm;}
            if(cnt == 0) continue;
            if(i % 2 == 0) add_edge(i, get_id(i, pm), cnt);
            else add_edge(get_id(i, pm), i, cnt);
        }
        if(cur > 1){
            if(i % 2 == 0) add_edge(i, get_id(i, cur), 1);
            else add_edge(get_id(i, cur), i, 1);
        }
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        if(a % 2 == 1){int tmp = b; b = a, a = tmp;}

        int g = __gcd(num[a], num[b]);
        for(int pm : pms){
            int cnt = 0;
            while(g % pm == 0){
                cnt ++;
                g /= pm;
            }
            if(cnt == 0) continue;
            add_edge(get_id(a, pm), get_id(b, pm), cnt);
        }
        if(g > 1){
            add_edge(get_id(a, g), get_id(b, g), 1);
        }
    }
    cout << max_flow(s, t) << endl;

}