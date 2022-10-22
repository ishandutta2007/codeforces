#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005

int X , n , a[N];
LL Q = 1e9 + 7;
LL power(LL A , LL B)
{
    LL ans = 1 ;
    while (B)
    {
        if (B & 1)
            ans *= A , ans %= Q;
        A *= A , A %= Q , B >>= 1;
    }
    return ans;
}


void work()
{
    int i , j ; LL sum = 0 , mx = 0 , ans;
    scanf("%d%d",&n,&X);
    map<LL , int> hash;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , sum += a[i] , mx = max(mx , (LL)a[i]);
    for (i = 1 ; i <= n ; ++ i)
        ++ hash[mx - a[i]];
    ans = sum - mx;
    map<LL , int> :: iterator it;
    for (it = hash.begin() ; it != hash.end() ;)
    {
        LL p = it -> first , q = it -> second;
        if (q && (q % X == 0)) hash[p + 1] += q / X , hash[p] = 0 , it = hash.lower_bound(p + 1);
        else ++ it;
    }
    for (it = hash.begin() ; it != hash.end() ; ++ it)
    {
        LL p = it -> first , q = it -> second;
        if (q)
        {
            ans += p;
            break;
        }
    }
    cout << power(X , min(sum , ans)) << endl;


}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
//    freopen("output.txt" , "w" , stdout);
//    int _; scanf("%d", &_) ; while (_ --)
//    while (~scanf("%s", s))
        work();
    return 0;
}