#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;
int n;
struct card {
    int a , b , c , d , id; 
    bool operator < (const card &R) const {
        return a < R.a;
    }
}C[N];
int d[M];
vector< pair<int , int> > t[N << 1];
int pre[M] , mcnt;
struct edge {
    int x , w , next;
}e[M << 3];
int Begin[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
inline void addedge(int x , int i , int w = 0) {
    e[mcnt] = (edge) {i , w , pre[x]} , pre[x] = mcnt ++;
}

void Build(int l , int r) {
    int p = id(l , r);
    t[p].resize(r - l + 1);
    if (l == r) {
        Begin[p] = n + 1;
        t[p][0] = make_pair(C[l].b , C[l].id);
        ++ n;
        addedge(n , C[l].id);
    } else {
        int mid = l + r >> 1;
        Build(l , mid);
        Build(mid + 1 , r);
        Begin[p] = n + 1;
        int L = id(l , mid) , R = id(mid + 1 , r);
        merge(t[L].begin(), t[L].end() ,t[R].begin(), t[R].end() , t[p].begin());
        for (int i = 1 ; i < r - l + 1 ; ++ i)
            addedge(n + 1 + i , n + i);
        for (int i = 0 ; i < r - l + 1 ; ++ i)
            addedge(n + 1 + i , t[p][i].second);
        n += r - l + 1;
    }
}
void connect(int l , int r , int top , int bot , int x , int w) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        int j = lower_bound(t[p].begin() , t[p].end() , make_pair(w , 1 << 30)) - t[p].begin() - 1;
        if (~j)
            addedge(x , Begin[p] + j , 1);
        return;
    } int mid = l + r >> 1;
    if (top <= mid) connect(l , mid , top , bot , x , w);
    if (bot > mid) connect(mid + 1 , r , top , bot , x , w);
}


int p[M];
int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d%d%d%d" , &C[i].a , &C[i].b ,&C[i].c , &C[i].d);        
        C[i].id = i;
    }
    sort(C + 1 , C + n + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        d[i] = C[i].a;
    }
    memset(pre , -1 , sizeof(pre));
    int K = n;
    Build(1 , K);
    for (int i = 1 ; i <= K ; ++ i) {
        int k = upper_bound(d + 1 , d + K + 1 , C[i].c) - d - 1;
        if (k > 0)
            connect(1 , K , 1 , k , C[i].id , C[i].d);
    }
    for (int i = 1 ; i <= n ; ++ i)
        d[i] = 1 << 30;
    deque< pair<int , int> > Q; 
    for (int i = 1 ; i <= K ; ++ i) {
        if (C[i].a == 0 && C[i].b == 0) {
            int x = C[i].id;
            d[x] = 1;
            Q.push_back(make_pair(x , 1)); 
        }
    }
    
    while (!Q.empty()) {
        int x = Q.front().first , w = Q.front().second; Q.pop_front();
        if (w != d[x]) continue;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (d[x] + e[i].w < d[y]) {
                d[y] = d[x] + e[i].w;
                p[y] = x;
                if (e[i].w)
                    Q.push_back(make_pair(y , d[y]));
                else
                    Q.push_front(make_pair(y , d[y]));
            }
        }
    }
  
    if (d[K] == 1 << 30)
        puts("-1");
    else {
        printf("%d\n" , d[K]);
        vector<int> res;
        int x = K;
        while (x) {
            if (x <= K)
                res.push_back(x);
            x = p[x];
        }
        reverse(res.begin() , res.end());
        for (int i = 0 ; i < (int)res.size() ; ++ i)
            printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    }
    return 0;
}