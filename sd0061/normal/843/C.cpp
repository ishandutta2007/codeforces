#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n , pre[N] , mcnt;
struct edge {
    int x , next;
} e[N << 1];

int s[N];
bool f[N];

vector< tuple<int , int , int> > res;

int root[N] , rootCnt , maxSize;

set< pair<int , int> > E;

pair<int , int> Find(int x , int fa , int cnt) {
    s[x] = 1; int m = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa) {
            Find(e[i].x , x , cnt);
            m = max(s[e[i].x] , m);
            s[x] += s[e[i].x];
        }
    m = max(m , cnt - s[x]);
    if (m < maxSize) {
        maxSize = m;
        rootCnt = 0;
    }
    if (m == maxSize) {
        root[rootCnt ++] = x;
    }
}

int getSize(int x , int fa) {
    int size = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa) {
            size += getSize(y , x);
        }
    }
    return size;
}


void update(int x , int y , int w) {
    if (x > y) swap(x , y);
    if (w > 0) {
        E.insert({x , y});
    } else {
        E.erase({x , y});
    }
}

pair<int , int> gao(int x , int fa) {
    int cur = fa;
    int beg = 0;
    int child = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa) {
            ++ child;
            int w , z;
            tie(w , z) = gao(y , x);
            if (cur == fa) {
                beg = z;
            }
            res.emplace_back(cur , x , z);
            update(cur , x , -1);
            update(cur , z , 1);
            cur = w;
        }
    }
    if (!child) {
        return {x , x};
    } else {
        return {beg , x};
    }
}
int leaf;
int boom(int x , int fa , vector<int> &v) {
    v.push_back(x);
    int child = 0;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa) {
            child ++;
            boom(y , x , v);
        }
    }
    //assert(child == 0 || child == 1);
}

int divide(int x , int cnt) {
    rootCnt = 0;
    maxSize = 1 << 30;
    Find(x , 0 , cnt);
    vector<int> p;
    for (int i = 0 ; i < rootCnt ; ++ i) {
        int x = root[i];
        f[x] = 1;
        p.emplace_back(x);
    } //cout << endl;
    //cout << p.size() << endl;
    //assert(p.size() == 1 || p.size() == 2);
    int R = p.back();
    for (auto &x : p) {
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!f[y]) {
                gao(y , x);
            }
        }
    }

    memset(pre , -1 ,sizeof(pre)); mcnt = 0;
    for (auto &it : E) {
        int x = it.first , y = it.second;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }

    for (auto &x : p) {
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!f[y]) {
                vector<int> route;
                route.push_back(x);
                boom(y , x , route);
                for (int j = route.size() - 2 ; j >= 0 ; -- j) {
                    res.emplace_back(route[j] , route[j + 1] , route.back());
                }
            }
        }
    }

}


int main() {
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        if (x > y) swap(x , y);
        E.insert({x , y});
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    divide(1 , n);
    printf("%d\n" , res.size());
    for (auto it : res) {
        printf("%d %d %d\n" , get<0>(it) , get<1>(it) , get<2>(it));
    }
}