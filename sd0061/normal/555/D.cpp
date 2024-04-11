#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , b[N];
pair<int , int> a[N];

int find(int dir , int x , int L) {
    if (!dir) {
        return upper_bound(a , a + n , make_pair(a[x].first + L , 1 << 30)) - a - 1;
    } else {
        return lower_bound(a , a + n , make_pair(a[x].first - L , -1 << 30)) - a;
    }
}

void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = i + 1;
        b[i + 1] = a[i].first;
    }
    sort(a , a + n);
    while (m --) {
        int x , l;
        scanf("%d%d" , &x , &l);
        int dir = 0 , pre = -1;
        int now = lower_bound(a , a + n , make_pair(b[x] , -1)) - a;
        while (1) {
            x = find(dir , now , l);
            if (x == now && now == pre) {
                printf("%d\n" , a[x].second);
                break;
            }
            int d = abs(a[x].first - a[now].first);
            if (x != pre) {
                l -= d;
                pre = now;
                now = x;
                dir ^= 1;
            } else {
                l = (l - d) % (d + d);
                pre = now;
                now = x;
                dir ^= 1;                
            }
        }
    }
}

int main() {
    work();    
    return 0;
}