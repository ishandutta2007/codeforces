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
#define N 100005
int n , m;
void work()
{
    int ans = 0 , res = 0;
    cin >> n >> m;
    while (n)
    {
        ans += n;
        res += n;
        n = res / m , res %= m;
    }
    cout << ans << endl;
}

int main()
{
 //   freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}