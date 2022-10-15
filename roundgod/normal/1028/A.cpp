/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-28 00:34:45
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,minx,miny,maxx,maxy;
string str[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>str[i];
    minx=miny=INF;maxx=maxy=-INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='B')
            {
                minx=min(minx,i);
                miny=min(miny,j);
                maxx=max(maxx,i);
                maxy=max(maxy,j);
            }
        }
    printf("%d %d\n",(minx+maxx)/2+1,(miny+maxy)/2+1);
    return 0;
}