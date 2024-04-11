#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , pre[N] , mcnt;
struct edge {
    int x , w , c , next;
} e[N << 1];
int res;
int s[N];
bool f[N];

pair<int , int> Find(int x , int fa , int cnt) {
    s[x] = 1; int m = 0;
    pair<int , int> res = make_pair(1 << 30 , -1);
    for (int i = pre[x] ; ~i ; i = e[i].next)
        if (!f[e[i].x] && e[i].x != fa) {
            res = min(res , Find(e[i].x , x , cnt));
            m = max(s[e[i].x] , m);
            s[x] += s[e[i].x];
        }
    m = max(m , cnt - s[x]);
    return min(res , make_pair(m , x));
}

struct opt {
    int a , b , c;
    bool operator < (const opt &R) const {
        return make_pair(a , b) < make_pair(R.a , R.b);
    }
};

vector< opt > V;

void Getdis(int x , int fa , int a , int b , int w) {
    // printf("%d : %d %d %d\n" , x , a , b , w);
    V.push_back((opt){a , b , w});
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa) {
            if (e[i].c == 0) {
                Getdis(y , x , a + 2 , b - 1 , (LL)w * e[i].w % Q);
            } else {
                Getdis(y , x , a - 1 , b + 2 , (LL)w * e[i].w % Q);
            }
        }
    }
}

inline void add(int& x , int y) {
    x += y; if (x >= Q) x -= Q;
}

int power(int a , int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (LL)res * a % Q;
        }
        a = (LL)a * a % Q;
        b >>= 1;
    }
    return res;
}
int inverse(int x) {
    return x == 1 ? 1 : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}
int d[N + N] , c[N + N] , D , p[N];
int get(vector<opt> V) {
    D = 0;
    int m = V.size();
    sort(V.begin() , V.end());
    for (auto it : V) {
        d[D ++] = it.b;
        d[D ++] = -it.b;
    }
    sort(d , d + D);
    D = unique(d , d + D) - d;
    for (int i = 0 ; i < m ; ++ i) {
        p[i] = lower_bound(d , d + D , V[i].b) - d + 1;
        V[i].b = lower_bound(d , d + D , -V[i].b) - d + 1;
    }
    for (int i = 1 ; i <= D ; ++ i) {
        c[i] = 0;
    }
    int res = 1;
    vector< pair<int , int> > id(m);
    for (int i = 0 ; i < m ; ++ i) {
        id[i] = {-V[i].a , i};
    }
    sort(id.begin() , id.end());
    for (int i = 0 , j = 0 ; i < m ; ++ i) {
        while (j < m && V[i].a >= id[j].first) {
            int l = id[j].second;
            for (int k = V[l].b ; k <= D ; k += k & -k) {
                ++ c[k];
            }
            ++ j;
        }
        int sum = 1 , num = 0;
        for (int k = p[i] ; k > 0 ; k -= k & -k) {
            num += c[k];
        }
        res = (LL) res * power(V[i].c , num) % Q;
    }
    return res;
}


void divide(int x , int cnt) {
    x = Find(x , 0 , cnt).second;
    f[x] = 1; vector< opt > W;
    W.push_back({0 , 0 , 1});
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            if (e[i].c == 0) {
                Getdis(y , x , 2 , -1 , e[i].w);
            } else {
                Getdis(y , x , -1 , 2 , e[i].w);
            }
            s[y] = V.size();
            res = (LL)res * inverse(get(V)) % Q;
            W.insert(W.end(), V.begin() , V.end());
            V.clear();
        }
    }
    res = (LL)res * get(W) % Q;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {
            divide(y , s[y]);
        }
    }
}


int main() {
    scanf("%d" , &n);
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (int i = 1 ; i < n ; ++ i) {
        int x , y , w , c;
        scanf("%d%d%d%d" , &x , &y , &w , &c);
        e[mcnt] = (edge) {y , w , c , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , w , c , pre[y]} , pre[y] = mcnt ++;
    }
    res = 1;
    divide(1 , n);
    cout << res << endl;
}