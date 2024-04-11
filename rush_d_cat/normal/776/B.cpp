#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int NICO = 100000 + 10;
int vis[NICO];
void getPrime()
{
    for(int i=2;i<NICO;i++)
    {
        if(!vis[i])
        {
            for(int j=2*i;j<NICO;j+=i)
            {
                vis[j] = 1;
            }
        }
    }
}
int main()
{
    int n;getPrime();
    cin >> n;
    if(n <= 2)
    {
        printf("1\n");
        for(int i=2;i<=n+1;i++)
        {
            printf("1 ");
        }
        return 0;
    }
    printf("2\n");
    for(int i=2;i<=n+1;i++)
    {
        printf("%d ", vis[i]?2:1);
    }
}