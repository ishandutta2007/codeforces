#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define N 100002
int n , m , a[N];
void work()
{
    int i , j , x , y;
    cin >> n >> m;
    int ans = 0;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (i = 1 ; i < n ; ++ i)
        ans = max(ans , a[i - 1] - a[i] - m);
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}