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
#include <set>
#include <map>
typedef long long LL;
using namespace std;

#define N 100005
char a[30] = "A......HI...M.O....TUVWXY.";
char s[N] , t[N];
void work()
{
    //cout << strlen(a) << endl;
    scanf("%s" , s);
    reverse(s , s + strlen(s));
    for (int i = 0 ; s[i] ; ++ i)
        t[i] = a[s[i] - 'A'];
    reverse(s , s + strlen(s));
    puts(strcmp(s , t) == 0 ? "YES" : "NO");
}

int main()
{
    //freopen("1.txt" , "r" , stdin);
    work();
    return 0;
}