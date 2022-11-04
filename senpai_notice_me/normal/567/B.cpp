#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1000005

bool peo_in[MAX_N];
int n,peo,nowpeo=0,ans=0;
char ch;

inline void Solve()
{
    if (ch=='+')
    {
        nowpeo++;
        ans=max(ans,nowpeo);
        peo_in[peo]=true;
    }
    else
    {
        if (peo_in[peo])
        {
            nowpeo--;
            peo_in[peo]=false;
        }
        else ans++;
    }
}

inline void Output()
{
    printf("%d",ans);
}

inline void Init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        getchar();
        scanf("%c%d",&ch,&peo);
        Solve();
    }
    Output();
}

int main()
{
    Init();
    
	return 0;
}