#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int h1,a1,c1,h2,a2;
int a[MAXN];
vector<int> mov;
int main()
{
    scanf("%d%d%d",&h1,&a1,&c1);
    scanf("%d%d",&h2,&a2);
    mov.clear();
    while(true)
    {
        if(h2<=a1)
        {
            mov.push_back(0);
            break;
        }
        else if(h1<=a2)
        {
            mov.push_back(1);
            h1+=c1-a2;
        }
        else
        {
            mov.push_back(0);
            h2-=a1;
            h1-=a2;
        }
    }
    printf("%d\n",mov.size());
    for(int i=0;i<mov.size();i++)
        if(mov[i]==1) puts("HEAL"); else puts("STRIKE");
    return 0;
}