#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , S , l;
int a[N] , L[N] , R[N];
int t[N << 1];
inline int id(int l , int r) {return l + r | l != r;}

void update(int l , int r , int x , int w) {
    int p = id(l , r);
    t[p] = min(t[p] , w);
    if (l != r) {
        int mid = l + r >> 1;
        if (x <= mid)
            update(l , mid , x , w);
        else
            update(mid + 1 , r , x , w);
    }
}

void query(int l , int r , int top , int bot , int& res) {
    int p = id(l , r);
    if (top <= l && r <= bot) {
        res = min(res , t[p]);
        return;
    } int mid = l + r >> 1;
    if (top <= mid) query(l , mid , top , bot , res);
    if (bot > mid) query(mid + 1 , r , top , bot , res);
}

void work() {
    int i , j , x;
    scanf("%d%d%d",&n,&S,&l);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    memset(t , 63 , sizeof(t));
    update(0 , n , 0 , 0);
    multiset<int> hash;

    i = 0 , j = 1;
    do {
        hash.insert(a[++ i]);
        while (*hash.rbegin() - *hash.begin() > S)
            hash.erase(hash.find(a[j ++]));
        L[i] = j - 1 , R[i] = i - l;
        if (L[i] <= R[i]) {
            x = 1 << 30;
            query(0 , n , L[i] , R[i] , x);
            ++ x;
            update(0 , n , i , x);
        }
        //printf("%d : %d %d\n" , i , L[i] , R[i]);
    } while(i < n);
    if (x > n)
        x = -1;
    printf("%d\n" , x);
}

int main() {
    work();
    return 0;
}