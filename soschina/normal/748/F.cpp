#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;
const int N = 2e5 + 1;
typedef pair<int, int> duo;

int n, k, u, v, head[N], nxt[N << 1], to[N << 1], eid = 1;
void addedge(int u, int v){
    to[eid] = v;
    nxt[eid] = head[u];
    head[u] = eid++;
}

int c[N], cnt[N], sum[N];
int r;

int len;
bool findans;
vector<int> vec[N];

struct node{
    int sz, id;
    node(int sz, int id) : sz(sz), id(id){}
    bool operator<(const node &b) const{
        return sz < b.sz;
    }
};
priority_queue<node> q;
set<int> up;

void ins(int i, int pre, int id){
    if(cnt[i]){
        vec[id].push_back(i);
        up.erase(i);
    }
    for (int e = head[i]; e; e = nxt[e])
        if(to[e] != pre)
            ins(to[e], i, id);
}

vector<duo> ans;

void dfs(int i, int pre){
    sum[i] = cnt[i];
    int maxsum = 0;
    for(int e = head[i]; e; e = nxt[e])
        if(to[e] != pre){
            dfs(to[e], i);
            sum[i] += sum[to[e]];
            maxsum = max(maxsum, sum[to[e]]);
        }
    maxsum = max(maxsum, 2 * k - sum[i]);
    if(maxsum <= k && !findans){
        r = i;
        findans = true;
        up.erase(i);
        for (int e = head[i]; e; e = nxt[e])
            if(to[e] != pre)
                ins(to[e], i, ++len);
        for (int x : up)
            vec[0].push_back(x);
        if(cnt[i])
            vec[++len].push_back(i);
        for (int j = 0; j <= len; j++)
            if(vec[j].size())
                q.push(node(vec[j].size(), j));
        while(q.size()){
            int x = q.top().id;
            q.pop();
            int y = q.top().id;
            q.pop();
            ans.push_back(duo(vec[x].back(), vec[y].back()));
            vec[x].pop_back(), vec[y].pop_back();
            if(vec[x].size())
                q.push(node(vec[x].size(), x));
            if(vec[y].size())
                q.push(node(vec[y].size(), y));
        }
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    for (int i = 1; i <= 2 * k; i++){
        scanf("%d", &c[i]);
        cnt[c[i]]++;
        up.insert(c[i]);
    }
    dfs(1, 0);
    printf("1\n%d\n", r);
    for(duo pr : ans)
        printf("%d %d %d\n", pr.first, pr.second, r);
    return 0;
}