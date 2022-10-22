#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 20000000;
int n , m;
 
int t[M] , cnt , c[M][2];
#define MID int mid = l + r >> 1
#define Left l , mid
#define Right mid + 1 , r

int newnode(int val = n + 1) {
    t[++ cnt] = val;
    return cnt;
}

void update(int& p , int l , int r , int top , int bot , int w) {
    if (!p) p = newnode();
    if (top <= l && r <= bot)
        t[p] = min(t[p] , w);
    else {
        MID;
        if (top <= mid) update(c[p][0] , Left , top , bot , w);
        if (bot > mid) update(c[p][1] , Right , top , bot , w);        
    }
}
int num;
int tcnt;
void get(int p , int l , int r , int x) {
    if (!p) return;
    num = min(num , t[p]);
    if (l == r)
        return;
    MID;
    if (x <= mid)
        get(c[p][0] , Left , x);
    else get(c[p][1] , Right , x);
}
set<int> X , Y;
void work() {
    char str[10];
    scanf("%d%d" , &n , &m);
    int t0 = newnode();
    int t1 = newnode();    
    update(t0 , 1 , n , 1 , n , n + 1);
    update(t1 , 1 , n , 1 , n , n + 1);
    
    while (m --) {
        int x , y;
        scanf("%d%d%s" , &x , &y , str);
        ++ tcnt;
        if (*str == 'U') {
            num = 1 << 30;
            if (X.count(x)) {
                puts("0");
            } else {
                get(t0 , 1 , n , x);
                printf("%d\n" , num - x);
                update(t1 , 1 , n , n - num + 2 , y , y);
            }
        } else {            
            num = 1 << 30;
            if (Y.count(y)) {
                puts("0");
            } else {
                get(t1 , 1 , n , y);
                printf("%d\n" , num - y);            
                update(t0 , 1 , n , n - num + 2 , x , x);
            }
        }
        X.insert(x);
        Y.insert(y);
    }
}

int main() {
    work();    
    return 0;
}