#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
bool cube[3][10];
int main()
{
    scanf("%d",&n);
    memset(cube,false,sizeof(cube));
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
        {
            int x;
            scanf("%d",&x);
            cube[i][x]=true;
        }
    for(int i=1;i<=99;i++)
    {
        if(i<10)
        {
            bool f=false;
            for(int j=0;j<n;j++)
                if(cube[j][i]) {f=true; break;}
            if(!f) {printf("%d\n",i-1); return 0;}
        }
        else
        {
            if(n==1) {printf("9\n"); return 0;}
            if(n==2)
            {
                int a=i/10,b=i%10;
                if((cube[0][a]&&cube[1][b])||(cube[0][b]&&cube[1][a])) continue;
                printf("%d\n",i-1);
                return 0;
            }
            if(n==3)
            {
                int a=i/10,b=i%10;
                if((cube[0][a]&&cube[1][b])||(cube[0][b]&&cube[1][a])||(cube[0][a]&&cube[2][b])||(cube[0][b]&&cube[2][a])||(cube[2][a]&&cube[1][b])||(cube[2][b]&&cube[1][a])) continue;
                printf("%d\n",i-1);
                return 0;
            }
        }
    }
    return 0;
}