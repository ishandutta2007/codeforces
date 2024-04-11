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
#define N 100005

int n , m;
char s[N] , t[N];

void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s", t);
        if (!i) {
            m = strlen(t);
            memset(s , '!' , sizeof(char) * m);
        }
        for (j = 0 ; j < m ; ++ j) {
            if (t[j] == '?')
                continue;
            if (s[j] == '!')
                s[j] = t[j];
            else if (s[j] != '?' && s[j] != t[j])
                s[j] = '?';
        }
    }
    for (i = 0 ; i < m ; ++ i)
        if (s[i] == '!')
            s[i] = 'a';
    puts(s);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
        work();
    return 0;
}