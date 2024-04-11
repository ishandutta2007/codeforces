#include <bits/stdc++.h>
 
using namespace std;
 
const int k_N = (1 << 20) + 10;
 
int n;
pair<int, int> edges[k_N];
 
vector<int> adjacent[k_N];
vector<int> cycle;
 
bool visited[k_N], invalid[k_N];
int start_index[k_N];
 
int dfs(int node, int x){
    visited[node] = true;
 
    int answer = 1;
    for(int index: adjacent[node]){
        int to;
        int first = edges[index].first % (1 << x);
        int second = edges[index].second % (1 << x);
 
        if(node == first)
            to = second;
        else
            to = first;
 
        if(!visited[to])
            answer += dfs(to, x);
    }
 
    return answer;
}
 
bool check(int x){
    for(int i = 0; i < (1 << x); ++i)
        adjacent[i].clear();
 
    for(int i = 0; i < n; ++i){
        adjacent[(edges[i].first % (1 << x))].push_back(i);
        adjacent[(edges[i].second % (1 << x))].push_back(i);
    }
 
    for(int i = 0; i < (1 << x); ++i)
        if(adjacent[i].size() & 1)
            return false;
 
    int cnt_v = 0;
    for(int i = 0; i < (1 << x); ++i)
        cnt_v += !adjacent[i].empty();
 
    for(int i = 0; i < (1 << x); ++i)
        visited[i] = false;
 
    for(int i = 0; i < (1 << x); ++i){
        if(adjacent[i].size()){
            if(dfs(i, x) != cnt_v)
                return false;
            break;
        }
    }
 
    return true;
}
 
void cycle_recursion(int node, int node_index, int before_index, int x){
    //cout << "cycle " << node << endl;
    for(; start_index[node] < adjacent[node].size(); ++start_index[node]){
        int index = adjacent[node][start_index[node]];
        if(invalid[index])
            continue;
 
        int to, to_index, other_index;
        int first = edges[index].first % (1 << x);
        int second = edges[index].second % (1 << x);
 
        if(node == first){
            to = second;
            to_index = index * 2 + 2;
            other_index = index * 2 + 1;
        }
        else{
            to = first;
            to_index = index * 2 + 1;
            other_index = index * 2 + 2;
        }
 
        invalid[index] = true;
        cycle_recursion(to, to_index, other_index, x);
    }
 
 
    cycle.push_back(node_index);
    if(before_index != -1)
        cycle.push_back(before_index);
}
 
void get_cycle(int x){
    cycle.clear();
 
    for(int i = 0; i < (1 << x); ++i){
        adjacent[i].clear();
        start_index[i] = 0;
    }
 
    for(int i = 0; i < n; ++i){
        adjacent[(edges[i].first % (1 << x))].push_back(i);
        adjacent[(edges[i].second % (1 << x))].push_back(i);
    }
 
    cycle_recursion(edges[0].first % (1 << x), 1, -1, x);
    cycle.pop_back();
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> edges[i].first >> edges[i].second;
 
    int l = 0, r = 20;
    while(l != r){
        int mid = (l + r + 1) >> 1;
        if(check(mid))
            l = mid;
        else
            r = mid - 1;
    }
 
    int answer = l;
    cout << answer << "\n";
 
    get_cycle(answer);
    for(int x: cycle)
        cout << x << " ";
    cout << "\n";
}