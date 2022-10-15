/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-12 19:43:26
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[4];
char mp[MAXN][MAXN];
int main()
{
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
    printf("%d %d\n",48,50);
    a[0]--;a[1]--;a[2]--;a[3]--;
    for(int i=0;i<48;i++)
        for(int j=0;j<50;j++)
            mp[i][j]='A'+i/12;
    for(int i=0;i<4;i++)
    {
        for(int j=i*12+1;j<(i+1)*12-2;j+=2)
            for(int k=0;k<50;k+=2)
            {
                for(int p=0;p<4;p++)
                    if(p!=i&&a[p]>0)
                    {
                        a[p]--;
                        mp[j][k]='A'+p;
                        break;
                    }
            }
    }
    for(int i=0;i<48;i++)
        printf("%s\n",mp[i]);
    return 0;
}