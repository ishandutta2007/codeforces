#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100044

char s[N];

void work()
{
    int i , j , k;
    vector<int> ans;
    scanf("%s" , s);
    for (i = 1 ; i <= 12 ; ++ i)
        if (12 % i == 0)
        {
            for (j = 0 ; j < 12 / i ; ++ j)
            {
                for (k = j ; k < 12 ; k += 12 / i)
                    if (s[k] == 'O')
                        break;
                if (k >= 12) break;
            }
            if (j < 12 / i)
                ans.push_back(i);
        }
    printf("%d" , ans.size());
    for (i = 0 ; i < ans.size() ; ++ i)
        printf(" %dx%d" , ans[i] , 12 / ans[i]);
    puts("");
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}