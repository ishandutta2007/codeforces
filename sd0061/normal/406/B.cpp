#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 1000005
int n;
bool f[N];

void work()
{
     int i , j , x = 0;
     vector<int> ans;
     scanf("%d",&n);
     for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&j);
        f[j] = 1;
     }
     for (i = 1 ; i <= 1000000 ; ++ i)
        if (f[i]) {
            if (!f[1000000 - i + 1])
                ans.push_back(1000000 - i + 1);
            else
                ++ x;
     }
     for (i = 1 ; i <= 1000000 && x ; ++ i)
        if (!f[i] && !f[1000000 - i + 1]) {
            x -= 2;
            ans.push_back(i) , ans.push_back(1000000 - i + 1);
        }
    printf("%d\n" , ans.size());
    for (i = 0 ; i < ans.size() ; ++ i)
        printf("%d " , ans[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}