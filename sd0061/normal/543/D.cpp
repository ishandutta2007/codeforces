#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n , m;
vector<int> e[N];
vector< pair<int , int> > R[N];
pair<int , int> f[N] , h[N];
void add(int& A , LL B) {
    A += B % Q;
    if (A >= Q)
        A -= Q;
}
pair<int , int> mergeA(pair<int , int> A , pair<int , int> B) {
    pair<int , int> C;
    add(C.first , (LL)A.first * B.first);
    add(C.second , (LL)A.first * B.first);
    add(C.second , (LL)A.first * B.second);
    add(C.second , (LL)A.second * B.first);
    add(C.second , (LL)A.second * B.first);
    add(C.second , (LL)A.second * B.second);
    return C;
}
pair<int , int> mergeB(pair<int , int> A , pair<int , int> B) {
    pair<int , int> C;
    add(C.first , (LL)A.first * B.first);
    add(C.second , (LL)A.second * B.first);
    add(C.second , (LL)A.first * B.second);
    add(C.second , (LL)A.second * B.second);
    return C;
}

int fa[N];
void dfs(int x) {

    for (int i = 0 ; i < e[x].size() ; ++ i) {
        int y = e[x][i];
        dfs(y);
    }
    pair<int , int> A(1 , 0);
    R[x].resize(e[x].size());
    for (int i = (int)e[x].size() - 1 ; i >= 0 ; -- i) {
        int y = e[x][i];
        A = mergeA(A , f[y]);
        R[x][i] = A;
    }
    f[x] = A;
}
void DFS(int x) {
    pair<int , int> A(1 , 0);
    for (int i = 0 ; i < e[x].size() ; ++ i) {
        int y = e[x][i];
        h[y] = A;
        if (i + 1 < e[x].size())
            h[y] = mergeB(h[y] , R[x][i + 1]);
        if (x != 1)
            h[y] = mergeA(h[y] , h[x]);
        DFS(y);
        A = mergeA(A , f[y]);
    }
}

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 2 ; i <= n ; ++ i) {
        scanf("%d" , &x) , y = i;
        e[x].push_back(y);
        fa[i] = x;
    }
    dfs(1);
    h[1] = make_pair(1 , 0);
    DFS(1);
    for (i = 1 ; i <= n ; ++ i) {
        pair<int , int> ret = f[i];
        if (fa[i])
            ret = mergeA(ret , h[i]);
        printf("%d\n" , (ret.first + ret.second) % Q);
    }
}

int main() {
    work();
    return 0;
}