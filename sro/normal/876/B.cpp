#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n,k,m,a[1000007];
vector<int> fnlay[1000007];

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        fnlay[a[i]%m].push_back(a[i]);
    }
    for(int i=0;i<m;i++)
        if((int)fnlay[i].size()>=k)
        {
            printf("Yes\n");
            for(int j=0;j<k;j++)printf("%d%c",fnlay[i][j],j==k-1?'\n':' ');
            return 0;
        }
    puts("No");
    return 0;
}