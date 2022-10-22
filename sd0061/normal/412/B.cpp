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
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 105


int n , k;
int a[N];

void work()
{
    int i , j;
    scanf("%d%d",&n,&k);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n);
    printf("%d\n" , a[n - k]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}