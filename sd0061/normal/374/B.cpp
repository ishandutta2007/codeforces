#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 100005;

int n;
char s[N];

void work()
{
    int i , j;
    long long ans = 1;
    scanf("%s" , s + 1);
    n = strlen(s + 1);
    for (i = 1 ; i <= n ; ++ i)
        s[i] -= '0';
    for (i = 1 ; i <= n ; ++ i)
    {
        j = i;
        while (j <= n && s[j + 1] + s[j] == 9)
            ++ j;
        if ((j - i + 1) % 2 == 1)
            ans *= (j - i + 2) >> 1;
        i = j;
    }
    cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&u))
        work();
    return 0;
}