#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 200005

int n , K ;
long long a[N];

void work()
{
    int i , j;
    cin >> n >> K;
    for (i = 1 ; i <= n ; ++ i)
        cin >> a[i] , a[i] += a[i - 1];
    pair<long long , int> ans(1LL << 60 , -1);
    for (i = K ; i <= n ; ++ i)
        ans = min(ans , make_pair(a[i] - a[i - K] , i - K + 1));
    cout << ans.second << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&k))
        work();
    return 0;
}