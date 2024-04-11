#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 605;

int n;
pair<int , int> a[N];

bool v[N][N];
bool f[N][N];
int p[N][N];

bool F(int i , int j) {
    if (i > j) return 1;
    if (v[i][j]) return f[i][j];
    v[i][j] = 1;
    for (int k = a[i].first ; k <= a[i].second ; ++ k) {
        if (i + 1 + k - 1 > j) continue;
        if (F(i + 1 , i + 1 + k - 1) && F(i + 1 + k , j)) {
            f[i][j] = 1;
            p[i][j] = k;
            break;
        }
    }
    return f[i][j];
}

void print(int l , int r) {
    if (l > r) return;
    putchar('(');
    print(l + 1 , l + 1 + p[l][r] - 1);
    putchar(')');
    print(l + 1 + p[l][r] , r);
}

void work() {
    int i , j , k , x , y;
    cin >> n;
    for (i = 1 ; i <= n ; ++ i) {
        cin >> x >> y;
        if (~x & 1)
            ++ x;
        if (~y & 1)
            -- y;
        if (x > y) {
            puts("IMPOSSIBLE");
            return;
        }
        a[i] = make_pair(x / 2 , y / 2);
        //printf("%d %d\n" , a[i].first , a[i].second);
    }
    memset(p , -1 , sizeof(p));
    if (!F(1 , n))
        puts("IMPOSSIBLE");
    else {
        print(1 , n);
    }
}
int main()
{
        work();
    return 0;
}