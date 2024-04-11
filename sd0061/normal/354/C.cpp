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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 300005
int n , K;
int s[1000005];

bool check(int p)
{
    for (int x = 0 ; x <= 1000000 ; x += p)
    {
        int yx = min(x + p - 1 , 1000000);
        int yn = x ? x + K + 1 : 1;
        if (yn <= yx && s[yn] < s[yx + 1]) return 0;
    }
    return 1;
}

void work()
{
    int i , j , x;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&x) , s[x + 1] = 1;
    for (i = 1 ; i <= 1000003 ; ++ i)
        s[i] += s[i - 1];
    for (i = 1000000 ; i > 0 ; -- i)
        if (check(i))
            break;
    printf("%d\n" , i);
}


int main()
{
    work();
    return 0;
}