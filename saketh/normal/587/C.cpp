#include <bits/stdc++.h>
using namespace std;

#define SIZE(t) ((int)((t).size()))

const int MAXN = 1e5 + 100;

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct seg_tree_vertex {
    vector<int> people;
    seg_tree_vertex() {}
    seg_tree_vertex(vector<int> arg) {
        sort(arg.begin(), arg.end());
        if (arg.size() > 10) arg.resize(10);
        people = arg;
    }

    seg_tree_vertex operator+(const seg_tree_vertex &v) {
        vector<int> res(people.size() + v.people.size());

        for (int i = 0; i < people.size(); i++)
            res[i] = people[i];

        for (int j = 0; j < v.people.size(); j++)
            res[j + people.size()] = v.people[j];

        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());

        if (res.size() > 10) res.resize(10);

        return { res };
    }
};

// the original tree
int N;
vector<vector<int> > G; 

// rooted tree as parent/child edges
vector<vector<int> > children;
vector<int> parent;

// vertex processing times for the DFS
vector<int> time_in, time_out;

// heavy-light decomposition of the tree into paths
vector< vector<int> > paths;
vector<int> path_id, path_offset;

// an interval tree for each path
vector<seg_tree<seg_tree_vertex>> trees;

void load() {
  //cin >> N;
  G.clear(); G.resize(N);
  for (int i=0; i<N-1; ++i) {
    int x,y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
}

vector<int> occupants[MAXN];

void dfs() {
  parent.clear(); parent.resize(N);
  children.clear(); children.resize(N);
  time_in.clear(); time_in.resize(N);
  time_out.clear(); time_out.resize(N);
  paths.clear();
  vector<bool> visited(N,false);
  vector<int> walk;
  vector<int> subtree_size(N,0);
  int time = 0;

  // run the DFS to compute lots of information
  stack<int> vertex, edge;
  visited[0]=true; time_in[0]=time; parent[0]=0;
  vertex.push(0); edge.push(0);
  while (!vertex.empty()) {
    ++time;
    int kde = vertex.top(); vertex.pop();
    int e = edge.top(); edge.pop();
    if (e == SIZE(G[kde])) {
      walk.push_back(kde);
      time_out[kde] = time;
      subtree_size[kde] = 1;
      for (int i=0; i<SIZE(children[kde]); ++i) subtree_size[kde] += subtree_size[children[kde][i]];
    } else {
      vertex.push(kde); edge.push(e+1);
      int kam = G[kde][e];
      if (!visited[kam]) { 
        visited[kam]=true; time_in[kam]=time; parent[kam]=kde; children[kde].push_back(kam);
        vertex.push(kam); edge.push(0);
      }
    }
  }

  // compute the heavy-light decomposition
  vector<bool> parent_edge_processed(N,false);
  parent_edge_processed[0] = true;
  for (int i=0; i<SIZE(walk); ++i) {
    int w = walk[i];
    if (parent_edge_processed[w]) continue;
    vector<int> this_path;
    this_path.push_back(w); 
    while (1) {
      bool is_parent_edge_heavy = (2*subtree_size[w] >= subtree_size[parent[w]]);
      parent_edge_processed[w] = true;
      w = parent[w];
      this_path.push_back(w);
      if (!is_parent_edge_heavy) break;
      if (parent_edge_processed[w]) break;
    }
    paths.push_back(this_path);
  }

  path_id.clear(); path_id.resize(N); path_id[0]=-1;
  path_offset.clear(); path_offset.resize(N);

  for (int i=0; i<SIZE(paths); ++i) 
    for (int j=0; j<SIZE(paths[i])-1; ++j) {
      path_id[ paths[i][j] ] = i;
      path_offset[ paths[i][j] ] = j;
    }

  trees.clear();
  for (int i=0; i<SIZE(paths); ++i) {
      int NV = SIZE(paths[i]);
      trees.push_back( seg_tree<seg_tree_vertex>(NV) );

      vector<seg_tree_vertex> leaves(NV);
      for (int j = 0; j < NV; j++) {
          leaves[j] = seg_tree_vertex(occupants[paths[i][j]]);
      }
      trees.back().set_leaves(leaves);
  }

}

// return whether x is an ancestor of y
inline bool is_ancestor(int x, int y) {
  return (time_in[y] >= time_in[x] && time_out[y] <= time_out[x]);
}

seg_tree_vertex query(int x, int y) {
  if (x==y) return seg_tree_vertex(occupants[x]);
  if (is_ancestor(x,y)) return query(y,x);
  int p = path_id[x];
  int lo = path_offset[x], hi = SIZE(paths[p])-1;
  if (is_ancestor(paths[p][hi], y)) {
    while (hi-lo > 1) {
      int med = (hi+lo)/2;
      if (is_ancestor(paths[p][med], y)) hi=med; else lo=med;
    }
    lo = path_offset[x]; // keep hi at found value, restore lo
  }
  seg_tree_vertex result = trees[p].query(lo,hi);
  return result + query(paths[p][hi],y);
}

int M, Q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> Q;
    load();

    for (int i = 0; i < M; i++) {
        int V;
        cin >> V;
        if (occupants[V-1].size() < 10)
        occupants[V-1].push_back(i+1);
    }
    
    dfs();

    while (Q--) {
      int x, y, a; 
      cin >> x >> y >> a;
      x--, y--;

      seg_tree_vertex res = query(x, y);

      int P = min(a, int(res.people.size()));
      cout << P << " ";
      for (int i = 0; i < P; i++) {
        cout << res.people[i] << " ";
      }

      cout << "\n";
    }
  return 0;
}