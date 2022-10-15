#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
int a,b,f,k;
int main()
{
    scanf("%d %d %d %d",&a,&b,&f,&k);
    int cnt=0;
    int x[4]={f,a-f,a-f,f};
    if((b<f)||(b<a-f)||(k>1&&(b<2*a-2*f))||(k>2&&b<2*f))
    {
        printf("-1\n");
        return 0;
    }
    int id=0;
    int t=b;
    int ans=0;
    while(true)
    {
        if(id==0&&t<x[id]) {id=3;cnt--;t=b;ans++;}
        else if(id==1&&t<x[id]) {t=b;ans++;}
        else if(id==2&&t<x[id]) {cnt--;id=1;t=b;ans++;}
        else if(id==3&&t<x[id]) {t=b;ans++;}
        else
        {
            t-=x[id]; cnt++;
            id++;
            if(id==4) id=0;
            if(cnt>=2*k) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}