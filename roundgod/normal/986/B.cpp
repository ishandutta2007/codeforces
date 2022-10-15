/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-29 23:58:02
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(used,false,sizeof(used));
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            int t=i;
            while(!used[t])
            {
                used[t]=true;
                t=a[t];
            }
            cnt++;
        }
    }
    if(!(cnt&1)) puts("Petr"); else puts("Um_nik");
    return 0;
}