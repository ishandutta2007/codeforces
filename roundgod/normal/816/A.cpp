#include<bits/stdc++.h>
using namespace std;
int t[24];
char c[5];
int x,y;
int main()
{
    memset(t,-1,sizeof(t));
    t[0]=0;
    t[1]=10;
    t[2]=20;
    t[3]=30;
    t[4]=40;
    t[5]=50;
    t[10]=1;
    t[11]=11;
    t[12]=21;
    t[13]=31;
    t[14]=41;
    t[15]=51;
    t[20]=2;
    t[21]=12;
    t[22]=22;
    t[23]=32;
    scanf("%s",c);
    x=(c[0]-48)*10+(c[1]-48);
    y=(c[3]-48)*10+(c[4]-48);
    if(t[x]>=y)
    {
        printf("%d\n",t[x]-y);
        return 0;
    }
    else
    {
        int s=0;
        s+=60-y;
        x++;
        if(x==24) x=0;
        while(t[x]==-1)
        {
            s+=60;
            x++;
            if(x==24) x=0;
        }
        printf("%d\n",s+t[x]);
        return 0;
     }
}