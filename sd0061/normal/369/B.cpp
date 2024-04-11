#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 205

int n , k , l , r , sk , s;

void work()
{
    cin >> n >> k >> l >> r >> s >> sk;
    for (int i = 0 ; i < k ; ++ i)
        printf("%d " , sk / k + (i < sk % k));
    sk = s - sk , k = n - k;
    for (int i = 0 ; i < k ; ++ i)
        printf("%d " , sk / k + (i < sk % k));
}

int main()
{
    //freopen("1.txt", "r" , stdin);
    //freopen("2.txt", "w" , stdout);

    //while (scanf("%d%d",&n,&m) , n || m)
    //int _; scanf("%d\n",&_); while (_ --)
        work();
    return 0;
}