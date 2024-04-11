#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int NICO = 100000 + 10;
int n, a[NICO], vis[NICO];
vector<int> v[NICO],tmp;
int main() 
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    int d=1,x=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i] != x)
        {
            vis[a[i]] = 1;
            d ++;
        } else {
            vis[a[i]] = 1;
            int tmp = a[i];
            while(vis[tmp] && tmp > 0)
            {
                printf("%d ", tmp);
                vis[tmp] = 0;
                tmp --;
            }
            x = tmp;
        }
        printf("\n");
    }
}