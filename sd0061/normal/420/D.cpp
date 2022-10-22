#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long LL;
#define N 1000005

struct Treap
{
    int nodecnt;
    int a[N][3];
    //int L[N] , R[N] , cnt[N];
    void clear() {
        nodecnt = 0;
    }
    Treap () {clear();}
    bool hey(int A , int B) {
        return (LL)rand() * (a[A][2] + a[B][2]) < (LL)a[A][2] * RAND_MAX;
    }
    int newnode(int val) {
        nodecnt = val , a[nodecnt][0] = a[nodecnt][1] = 0;
        a[nodecnt][2] = 1 ;
        return nodecnt;
    }
    void pushup(int x) {
        a[x][2] = 1;
        if (a[x][0]) a[x][2] += a[a[x][0]][2];
        if (a[x][1]) a[x][2] += a[a[x][1]][2];
    }
    void merge(int& p , int x , int y) {
        if (!x || !y)
            p = x | y;
        else if ( hey(x , y) ) // key[x] < key[y]
            merge(a[x][1] , a[x][1] , y) , pushup(p = x);
        else
            merge(a[y][0] , x , a[y][0]) , pushup(p = y);
    }
    void split(int p , int& x , int& y , int size) {
        if (!size) {
            x = 0 , y = p;
            return;
        }
        if (a[a[p][0]][2] >= size)
            y = p , split(a[p][0] , x , a[y][0] , size) , pushup(y);
        else
            x = p , split(a[p][1] , a[x][1] , y , size - a[a[p][0]][2] - 1) , pushup(x);
    }
    void Build(int& p , int l , int r) {
        int mid = (l + r) >> 1;
        p = newnode(mid);
        if (l < mid) Build(a[p][0] , l , mid - 1);
        if (mid < r) Build(a[p][1] , mid + 1 , r);
        pushup(p);
    }
};
Treap T;
int n , m;
int ans[N];
bool used[N];
void RD(int& x)
{
    x = 0; char c;
    for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
    for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}
void work()
{
    int i , j , k , x , y , z;
    int root = 0;
    scanf("%d%d",&n,&m);
    T.Build(root , 1 , n);
    for (i = 0 ; i < m ; ++ i) {
        RD(j) , RD(k); // a[k] = j;
        T.split(root , x , z , k);
        T.split(x , x , y , k - 1); // y -> a[k]
        if (ans[y] && ans[y] != j)
            break;
        if (!ans[y]) {
            if (used[j])
                break;
            used[j] = 1 , ans[y] = j;
        }
        T.merge(x , y , x);
        T.merge(root , x , z);
    }
    if (i < m) {
        puts("-1");
        return;
    }
    j = 1;
    for (i = 1 ; i <= n ; ++ i) {
        if (!ans[i]) {
            while (used[j])
                ++ j;
            used[j] = 1 , ans[i] = j;
        }
        printf("%d%c" , ans[i] , " \n"[i == n]);
    }

}

int main()
{
    work();
    return 0;
}