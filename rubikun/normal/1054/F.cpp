#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=2005;
const ll INF=1LL<<60;

// 

#ifndef ATCODER_INTERNAL_QUEUE_HPP
#define ATCODER_INTERNAL_QUEUE_HPP 1
#include <vector>
namespace atcoder {
    namespace internal {
        template <class T> struct simple_queue {
            std::vector<T> payload;
            int pos = 0;
            void reserve(int n) { payload.reserve(n); }
            int size() const { return int(payload.size()) - pos; }
            bool empty() const { return pos == int(payload.size()); }
            void push(const T& t) { payload.push_back(t); }
            T& front() { return payload[pos]; }
            void clear() {
                payload.clear();
                pos = 0;
            }
            void pop() { pos++; }
        };
    }  // namespace internal
}  // namespace atcoder
#endif  // ATCODER_INTERNAL_QUEUE_HPP

#ifndef ATCODER_MAXFLOW_HPP
#define ATCODER_MAXFLOW_HPP 1
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>
namespace atcoder {
    template <class Cap> struct mf_graph {
    public:
        mf_graph() : _n(0) {}
        mf_graph(int n) : _n(n), g(n) {}
        int add_edge(int from, int to, Cap cap) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            assert(0 <= cap);
            int m = int(pos.size());
            pos.push_back({from, int(g[from].size())});
            g[from].push_back(_edge{to, int(g[to].size()), cap});
            g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
            return m;
        }
        struct edge {
            int from, to;
            Cap cap, flow;
        };
        edge get_edge(int i) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
        }
        std::vector<edge> edges() {
            int m = int(pos.size());
            std::vector<edge> result;
            for (int i = 0; i < m; i++) {
                result.push_back(get_edge(i));
            }
            return result;
        }
        void change_edge(int i, Cap new_cap, Cap new_flow) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            assert(0 <= new_flow && new_flow <= new_cap);
            auto& _e = g[pos[i].first][pos[i].second];
            auto& _re = g[_e.to][_e.rev];
            _e.cap = new_cap - new_flow;
            _re.cap = new_flow;
        }
        Cap flow(int s, int t) {
            return flow(s, t, std::numeric_limits<Cap>::max());
        }
        Cap flow(int s, int t, Cap flow_limit) {
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            std::vector<int> level(_n), iter(_n);
            internal::simple_queue<int> que;
            auto bfs = [&]() {
                std::fill(level.begin(), level.end(), -1);
                level[s] = 0;
                que.clear();
                que.push(s);
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();
                    for (auto e : g[v]) {
                        if (e.cap == 0 || level[e.to] >= 0) continue;
                        level[e.to] = level[v] + 1;
                        if (e.to == t) return;
                        que.push(e.to);
                    }
                }
            };
            auto dfs = [&](auto self, int v, Cap up) {
                if (v == s) return up;
                Cap res = 0;
                int level_v = level[v];
                for (int& i = iter[v]; i < int(g[v].size()); i++) {
                    _edge& e = g[v][i];
                    if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                    Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                    if (d <= 0) continue;
                    g[v][i].cap += d;
                    g[e.to][e.rev].cap -= d;
                    res += d;
                    if (res == up) break;
                }
                return res;
            };
            Cap flow = 0;
            while (flow < flow_limit) {
                bfs();
                if (level[t] == -1) break;
                std::fill(iter.begin(), iter.end(), 0);
                while (flow < flow_limit) {
                    Cap f = dfs(dfs, t, flow_limit - flow);
                    if (!f) break;
                    flow += f;
                }
            }
            return flow;
        }
        std::vector<bool> min_cut(int s) {
            std::vector<bool> visited(_n);
            internal::simple_queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int p = que.front();
                que.pop();
                visited[p] = true;
                for (auto e : g[p]) {
                    if (e.cap && !visited[e.to]) {
                        visited[e.to] = true;
                        que.push(e.to);
                    }
                }
            }
            return visited;
        }
    private:
        int _n;
        struct _edge {
            int to, rev;
            Cap cap;
        };
        std::vector<std::pair<int, int>> pos;
        std::vector<std::vector<_edge>> g;
    };
}  // namespace atcoder
#endif  // ATCODER_MAXFLOW_HPP
#ifndef ATCODER_MINCOSTFLOW_HPP
#define ATCODER_MINCOSTFLOW_HPP 1
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>
namespace atcoder {
    template <class Cap, class Cost> struct mcf_graph {
    public:
        mcf_graph() {}
        mcf_graph(int n) : _n(n), g(n) {}
        int add_edge(int from, int to, Cap cap, Cost cost) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            int m = int(pos.size());
            pos.push_back({from, int(g[from].size())});
            g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
            g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
            return m;
        }
        struct edge {
            int from, to;
            Cap cap, flow;
            Cost cost;
        };
        edge get_edge(int i) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
            };
        }
        std::vector<edge> edges() {
            int m = int(pos.size());
            std::vector<edge> result(m);
            for (int i = 0; i < m; i++) {
                result[i] = get_edge(i);
            }
            return result;
        }
        std::pair<Cap, Cost> flow(int s, int t) {
            return flow(s, t, std::numeric_limits<Cap>::max());
        }
        std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
            return slope(s, t, flow_limit).back();
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
            return slope(s, t, std::numeric_limits<Cap>::max());
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            assert(s != t);
            // variants (C = maxcost):
            // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
            // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
            std::vector<Cost> dual(_n, 0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            std::vector<bool> vis(_n);
            auto dual_ref = [&]() {
                std::fill(dist.begin(), dist.end(),
                          std::numeric_limits<Cost>::max());
                std::fill(pv.begin(), pv.end(), -1);
                std::fill(pe.begin(), pe.end(), -1);
                std::fill(vis.begin(), vis.end(), false);
                struct Q {
                    Cost key;
                    int to;
                    bool operator<(Q r) const { return key > r.key; }
                };
                std::priority_queue<Q> que;
                dist[s] = 0;
                que.push(Q{0, s});
                while (!que.empty()) {
                    int v = que.top().to;
                    que.pop();
                    if (vis[v]) continue;
                    vis[v] = true;
                    if (v == t) break;
                    // dist[v] = shortest(s, v) + dual[s] - dual[v]
                    // dist[v] >= 0 (all reduced cost are positive)
                    // dist[v] <= (n-1)C
                    for (int i = 0; i < int(g[v].size()); i++) {
                        auto e = g[v][i];
                        if (vis[e.to] || !e.cap) continue;
                        // |-dual[e.to] + dual[v]| <= (n-1)C
                        // cost <= C - -(n-1)C + 0 = nC
                        Cost cost = e.cost - dual[e.to] + dual[v];
                        if (dist[e.to] - dist[v] > cost) {
                            dist[e.to] = dist[v] + cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                            que.push(Q{dist[e.to], e.to});
                        }
                    }
                }
                if (!vis[t]) {
                    return false;
                }
                for (int v = 0; v < _n; v++) {
                    if (!vis[v]) continue;
                    // dual[v] = dual[v] - dist[t] + dist[v]
                    //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
                    //         = - shortest(s, t) + dual[t] + shortest(s, v)
                    //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
                    dual[v] -= dist[t] - dist[v];
                }
                return true;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost = -1;
            std::vector<std::pair<Cap, Cost>> result;
            result.push_back({flow, cost});
            while (flow < flow_limit) {
                if (!dual_ref()) break;
                Cap c = flow_limit - flow;
                for (int v = t; v != s; v = pv[v]) {
                    c = std::min(c, g[pv[v]][pe[v]].cap);
                }
                for (int v = t; v != s; v = pv[v]) {
                    auto& e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                Cost d = -dual[s];
                flow += c;
                cost += c * d;
                if (prev_cost == d) {
                    result.pop_back();
                }
                result.push_back({flow, cost});
                prev_cost = cost;
            }
            return result;
        }
    private:
        int _n;
        struct _edge {
            int to, rev;
            Cap cap;
            Cost cost;
        };
        std::vector<std::pair<int, int>> pos;
        std::vector<std::vector<_edge>> g;
    };
}  // namespace atcoder
#endif  // ATCODER_MINCOSTFLOW_HPP

vector<int> xx[MAX],yy[MAX];

int idx(int x,vector<int> X){
    return int(lower_bound(all(X),x)-X.begin());
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> xkouho,ykouho,x(N),y(N);
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
        xkouho.push_back(x[i]);
        ykouho.push_back(y[i]);
    }
    
    sort(all(xkouho));
    sort(all(ykouho));
    
    xkouho.erase(unique(all(xkouho)),xkouho.end());
    ykouho.erase(unique(all(ykouho)),ykouho.end());
    
    for(int i=0;i<N;i++){
        xx[idx(x[i],xkouho)].push_back(idx(y[i],ykouho));
        yy[idx(y[i],ykouho)].push_back(idx(x[i],xkouho));
    }
    
    int siX=si(xkouho),siY=si(ykouho);
    
    vector<vector<int>> X,Y;
    
    for(int i=0;i<siX;i++){
        sort(all(xx[i]));
        for(int j=0;j+1<si(xx[i]);j++){
            X.push_back({i,xx[i][j],i,xx[i][j+1]});
        }
    }
    
    for(int j=0;j<siY;j++){
        sort(all(yy[j]));
        for(int i=0;i+1<si(yy[j]);i++){
            Y.push_back({yy[j][i],j,yy[j][i+1],j});
        }
    }
    
    atcoder::mf_graph<int> G(si(X)+si(Y)+2);
    
    int s=si(X)+si(Y),t=si(X)+si(Y)+1;
    
    for(int i=0;i<si(X);i++){
        for(int j=0;j<si(Y);j++){
            auto a=X[i],b=Y[j];
            if(a[1]<b[1]&&b[1]<a[3]&&b[0]<a[0]&&a[0]<b[2]) G.add_edge(i,si(X)+j,1);
        }
    }
    
    for(int i=0;i<si(X);i++) G.add_edge(s,i,1);
    for(int j=0;j<si(Y);j++) G.add_edge(si(X)+j,t,1);
    
    int f=G.flow(s,t);
    
    vector<vector<int>> ansx,ansy;
    
    auto ed=G.edges();
    
    vector<vector<int>> cutx,cuty;
    
    vector<int> visit(si(X)+si(Y)+2);
    visit[s]=1;
    
    for(int t=0;t<si(X)+si(Y)+2;t++){
        for(auto e:ed){
            if(e.flow==1){
                if(visit[e.to]==0) continue;
                visit[e.from]=1;
            }else{
                if(visit[e.from]==0) continue;
                visit[e.to]=1;
            }
        }
    }
    
    //for(int i=0;i<si(visit);i++) cout<<visit[i]<<endl;
    
    //for(auto e:ed) cout<<e.from<<" "<<e.to<<" "<<e.flow<<endl;
    
    for(int i=0;i<si(X);i++){
        if(visit[i]==0){
            cutx.push_back({xkouho[X[i][0]],ykouho[X[i][1]],xkouho[X[i][2]],ykouho[X[i][3]]});
        }
    }
    
    for(int j=0;j<si(Y);j++){
        if(visit[si(X)+j]){
            cuty.push_back({xkouho[Y[j][0]],ykouho[Y[j][1]],xkouho[Y[j][2]],ykouho[Y[j][3]]});
        }
    }
    
    int j=0;
    
    for(int i=0;i<siX;i++){
        int a=ykouho[xx[i].front()];
        while(j<si(cutx)&&xkouho[i]==cutx[j][0]){
            ansx.push_back({xkouho[i],a,xkouho[i],cutx[j][1]});
            a=cutx[j][3];
            j++;
        }
        ansx.push_back({xkouho[i],a,xkouho[i],ykouho[xx[i].back()]});
    }
    
    j=0;
    
    for(int i=0;i<siY;i++){
        int a=xkouho[yy[i].front()];
        while(j<si(cuty)&&ykouho[i]==cuty[j][1]){
            ansy.push_back({a,ykouho[i],cuty[j][0],ykouho[i]});
            a=cuty[j][2];
            j++;
        }
        ansy.push_back({a,ykouho[i],xkouho[yy[i].back()],ykouho[i]});
    }
    
    cout<<si(ansy)<<endl;
    for(auto a:ansy){
        for(int b:a) cout<<b<<" ";
        cout<<endl;
    }
    
    cout<<si(ansx)<<endl;
    for(auto a:ansx){
        for(int b:a) cout<<b<<" ";
        cout<<endl;
    }
}