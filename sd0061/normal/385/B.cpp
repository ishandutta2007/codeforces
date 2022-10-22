#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define N 100002
int n , ans;
char s[N];
vector<int> f;
void work()
{
    int i , j , x , y;
    scanf("%s" , s + 1) , n = strlen(s + 1);
    int ans = n * (n - 1) / 2;
    for (i = 1 ; i + 3 <= n ; ++ i)
        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
            f.push_back(i);
    if (f.size())
    {
        x = f[0] + 2;
        ans -= x * (x - 1) / 2;
    }
    else
    {
        cout << 0 << endl;
        return;
    }
    for (i = 0 ; i + 1 < f.size() ; ++ i)
    {
        x = f[i] , y = f[i + 1];
        x = y - x + 2;
        ans -= x * (x - 1) / 2;
    }
    if (f.size())
    {
        x = n - f[f.size() - 1];
        ans -= x * (x - 1) / 2;
    }
    cout << ans + f.size() << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}