#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;
const int MAX_N = 5000;

template <typename T>
struct edge
{
    int from, to;
    T cost;
};

template <typename T>
struct Edges
{
    int n;
    vector<edge<T>> edges;
    T d[MAX_N + 4];
    
    Edges(int n) : n(n) {};
    
    void add_edge(int from, int to, int cost){
        edges.push_back(edge<T>{from, to, cost});
    }
    
    bool Bellman_Ford(int s){
        fill(d, d + n, 0);
        d[s] = 0;
        for(int i = 0; i < n - 1; i++){
            for(edge<T> &e : edges){
                d[e.to] = min(d[e.to], d[e.from] + e.cost);
            }
        }
        for(edge<T> &e : edges) if(d[e.to] > d[e.from] + e.cost) return false;
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Edges<int> e(n);
    vector<int> v[5003], rv[5003];
    int a[5003], b[5003];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        e.add_edge(a[i], b[i], -1);
        v[a[i]].push_back(i);
        rv[b[i]].push_back(i);
    }
    if(e.Bellman_Ford(0)){
        cout << 1 << endl;
        for(int i = 0; i < m; i++) cout << "1 ";
        cout << endl;
        return 0;
    }
    int ans[5003] {0};
    for(int i = 0; i < n; i++){
        for(int x : v[i]){
            if(ans[x] == 0) ans[x] = 1;
        }
        for(int x : rv[i]){
            if(ans[x] == 0) ans[x] = 2;
        }
    }
    cout << 2 << endl;
    for(int i = 0; i < m; i++) cout << ans[i] << " ";
}