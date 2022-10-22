#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#define N 200005
using namespace std;
typedef long long LL;
int n , k , a[N];
pair<LL , int> ans;

void  work()
{
    int i , j , t;
    cin >> n >> k;
    for (i = 1 ; i <= n ; ++ i)
        cin >> a[i] , a[i + n] = a[i];
    ans.first = 1LL << 60;
    for (i = 1 ; i <= k ; ++ i)
    {
        LL sum = 0;
        for (j = i , t = 0 ; t < n / k ; j += k , ++ t)
            sum += a[j];
        ans = min(ans , make_pair(sum , i));
    }
    printf("%d\n" , ans.second);
}


int main()
{
    //freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}