#include <cstdio>
#include <vector>
using namespace std;
const int N = 200005;

int n , m;
int a[N] , c[N];
void gauss(vector<int> &v) {
    int Rank = 0 , n = v.size();
    for (int i = 0 ; i < 30 ; ++ i) {
        int pivot = Rank;
        while (pivot < n && (~v[pivot] >> i & 1))
            ++ pivot;
        if (pivot >= n)
            continue;
        swap(v[Rank] , v[pivot]);
        for (int j = 0 ; j < n ; ++ j)
            if (j != Rank && (v[j] >> i & 1))
                v[j] ^= v[Rank];
        ++ Rank;
    }
    v.resize(Rank);
}
vector<int> operator + (const vector<int> &A , const vector<int> &B) {
    vector<int> C = A;
    C.insert(C.end() , B.begin() , B.end());
    gauss(C);
    return C;
}
vector<int> t[N << 1];
inline int id(int l , int r) {
    return l + r | l != r;
}
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r 

void build(int l , int r) {
    int p = id(l , r);
    if (l == r) {
        t[p].push_back(a[l]);
    } else {
        MID;
        build(Left);
        build(Right);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}
void update(int l , int r , int x) {
    int p = id(l , r);
    if (l == r) {
        t[p].clear();
        t[p].push_back(a[x]);
    } else {
        MID;
        if (x <= mid)
            update(Left , x);
        else
            update(Right , x);
        t[p] = t[id(Left)] + t[id(Right)];
    }
}
void query(int l , int r , int top , int bot , vector<int> &res) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        res = res + t[p];
    } else {
        MID;
        if (top <= mid)
            query(Left , top , bot , res);
        if (bot > mid)
            query(Right , top , bot , res);
    }
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        int x = a[i] ^ a[i - 1];
        for (int j = i ; j <= n ; j += j & -j)
            c[j] ^= x;        
    }
    for (int i = n ; i > 0 ; -- i)
        a[i] ^= a[i - 1];
    build(1 , n);
    for (int i = 0 ; i < m ; ++ i) {
        int j , l , r , w;
        scanf("%d%d%d" , &j , &l , &r);
        if (j == 1) {
            scanf("%d" , &w);
            for (int j = l ; j <= n ; j += j & - j)
                c[j] ^= w;
            for (int j = r + 1 ; j <= n ; j += j & -j)
                c[j] ^= w;
            a[l] ^= w;
            update(1 , n , l);
            if (r < n) {
                a[r + 1] ^= w;
                update(1 , n , r + 1);
            }
        } else {
            vector<int> res;
            w = 0;
            for (int j = l ; j > 0 ; j -= j & -j)
                w ^= c[j];
            res.push_back(w);
            ++ l;
            if (l <= r)
                query(1 , n , l , r , res);
            gauss(res);
            printf("%d\n" , 1 << res.size());
        }
    }
    return 0;
}