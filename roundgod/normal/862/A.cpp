#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,x,y;
bool save[MAXN];
int main()
{
    scanf("%d %d",&n,&x);
    int cnt=0;
    memset(save,false,sizeof(save));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&y);
        save[y]=true;
    }
    for(int i=0;i<x;i++)
        if(!save[i]) cnt++;
    if(save[x]) cnt++;
    printf("%d\n",cnt);
    return 0;
}