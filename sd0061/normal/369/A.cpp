#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 205

int n , m , k;

void work()
{
    int i , x , cnt = 0;
    cin >> n >>m >>k;
    while (n --)
    {
        cin >> x;
        if (x == 1)
        {
            -- m;
            if (!~m)
                ++ m , ++ cnt;
        }
        else
        {
            -- k;
            if (!~k)
            {
                ++ k;
                -- m;
                if (!~m)
                    ++ m , ++ cnt;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    //freopen("1.txt", "r" , stdin);
    //freopen("2.txt", "w" , stdout);

    //while (scanf("%d%d",&n,&m) , n || m)
    //int _; scanf("%d\n",&_); while (_ --)
        work();
    return 0;
}