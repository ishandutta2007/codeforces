#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

int t[500005];
bool b[500005];
int ans[500005];
bool f[500005];
bool d[500005];

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &t[i]);
        t[i]--;
        if(t[i] > (int)g.g[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    int k = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++){
        if(t[i] == 0){
            d[i] = true;
            que.push(P(t[i], i));
        }
    }
    while(que.size()){
        P p = que.top();
        que.pop();
        int u = p.second;
        b[u] = true;
        for(int j = 0; j < t[u]; j++) f[j] = false;
        for(int v : g.g[u]){
            if(b[v]){
                if(t[v] == t[u]){
                    cout << -1 << endl;
                    return 0;
                }
                f[t[v]] = true;
            }
            else if(!d[v]){
                que.push(P(t[v], v));
                d[v] = true;
            }
        }
        for(int j = 0; j < t[u]; j++){
            if(!f[j]){
                cout << -1 << endl;
                return 0;
            }
        }
        ans[k] = u;
        k++;
    }
    for(int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
    cout << endl;
}