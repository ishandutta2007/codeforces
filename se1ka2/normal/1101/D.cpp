#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    
    void init(Graph &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
};

int a[200005];
P p[200005];
map<int, int> mp[200005];

int main()
{
    bool pr[500];
    vector<int> prime;
    fill(pr, pr + 500, true);
    for(int i = 2; i < 500; i++){
        if(pr[i]) prime.push_back(i);
        for(int j = i; j <= 500; j += i) pr[j] = false;
    }
    int n;
    cin >> n;
    Graph g(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }
    Tree t(g, 0);
    for(int i = 0; i < n; i++) p[i] = P(t.dpt[i], i);
    sort(p, p + n, greater<P>());
    int ans = 0;
    for(int c = 0; c < n; c++){
        int i = p[c].second;
        for(int q : prime){
            if(a[i] % q == 0){
                while(a[i] % q == 0) a[i] /= q;
                int f = 0, s = 0;
                for(int ch : t.t[i]){
                    int x = mp[ch][q];
                    if(x > f){
                        s = f;
                        f = x;
                    }
                    else if(x > s){
                        s = x;
                    }
                }
                ans = max(ans, f + s + 1);
                mp[i][q] = f + 1;
            }
        }
        if(a[i] != 1){
            int q = a[i];
            int f = 0, s = 0;
            for(int ch : t.t[i]){
                int x = mp[ch][q];
                if(x > f){
                    s = f;
                    f = x;
                }
                else if(x > s){
                    s = x;
                }
            }
            ans = max(ans, f + s + 1);
            mp[i][q] = f + 1;
        }
    }
    cout << ans << endl;
}