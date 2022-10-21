#include <bits/stdc++.h>
using namespace std;

const int N = 200050, B = 31, INF = (int)1e9;
typedef pair<int, int> P;
typedef long long ll;

int n,x;
int cnt = 1;
int bit[B];
int u[N];
vector<int> cps[N];
vector<int> num;

void umin(P &a, P b){
    if(a.first > b.first){
        a.first = b.first;
        a.second = b.second;
    }
}

struct node{
    int nxt[2], cnt[2];
    int ed;
    node(){nxt[0] = nxt[1] = -1, cnt[0] = cnt[1] = 0; ed = -1;}
}trie[N * B];

int find(int i){return u[i] == i ? i : u[i] = find(u[i]);}
void unite(int i, int j){u[find(i)] = find(j);}

void add(int x, int ind = -1){
    for(int i = 0; i < 30; i++) bit[i] = x % 2, x /= 2;
    int cur = 0;
    for(int i = 30 - 1; i >= 0; i--){
        int b = bit[i];
        trie[cur].cnt[b]++;
        if(trie[cur].nxt[b] == -1) trie[cur].nxt[b] = cnt++;
        cur = trie[cur].nxt[b];
    }
    if(ind != -1) trie[cur].ed = ind;
}

void remove(int x){
    for(int i = 0; i < 30; i++) bit[i] = x % 2, x /= 2;
    int cur = 0;
    for(int i = 30 - 1; i >= 0; i--){
        int b = bit[i];
        trie[cur].cnt[b]--;
        cur = trie[cur].nxt[b];
    }
}

pair<int, int> find_nearst(int x){
    for(int i = 0; i < 30; i++) bit[i] = x % 2, x /= 2;
    int res = 0, cur = 0;
    for(int i = 30 - 1; i >= 0; i--){
        int b = bit[i];
        res *= 2;
        if(trie[cur].cnt[b] > 0) cur = trie[cur].nxt[b];
        else cur = trie[cur].nxt[1-b], res ++;
    }
    return make_pair(res, trie[cur].ed);
};

int main(){
    for(int i = 0; i < N; i++) u[i] = i;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    auto it = unique(num.begin(), num.end());
    num.resize((unsigned int)distance(num.begin(), it));

    n = num.size();
    for(int i = 0; i < n; i++) add(num[i], i);

    ll res = 0;
    int tcnt = n;
    for(int i = 0; i < tcnt; i++) cps[i].push_back(i);
    while(tcnt > 1){
        for(int i = 0; i < n; i++){
            if(cps[i].empty()) continue;
            for(int j : cps[i]) remove(num[j]);
            P mn = {INF, -1};
            for(int j : cps[i]) umin(mn, find_nearst(num[j]));
            if(find(cps[i][0]) != find(mn.second)){
                res += mn.first;
//                cout << "uniting " << cps[i][0] <<  " and " << mn.second << " with weight " << mn.first << endl;
                unite(cps[i][0], mn.second);
                tcnt --;
            }
            for(int j : cps[i]) add(num[j]);
//            assert(trie[i].cnt[0] + trie[i].cnt[1] == n);
        }
        for(int i = 0; i < n; i++) cps[i].clear();
        for(int i = 0; i < n; i++) cps[find(i)].push_back(i);
    }
    printf("%I64d\n", res);
}