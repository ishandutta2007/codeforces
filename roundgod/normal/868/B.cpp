#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int h,m,s,t1,t2;
int main()
{
    scanf("%d %d %d %d %d",&h,&m,&s,&t1,&t2);
    h*=3600;
    h+=m*60+s;
    m*=720;
    m+=s*12;
    s*=720;
    t1*=3600;t2*=3600;
    bool f1=true,f2=true;
    if(t1==t2)
    {
        printf("YES\n");
        return 0;
    }
    if(t1<t2)
    {
        for(int i=t1+1;i<t2;i++)
            if((i%43200==h%43200)||(i%43200==m%43200)||(i%43200==s%43200)) f1=false;
        for(int i=t1+43199;i>t2;i--)
            if((i%43200==h%43200)||(i%43200==m%43200)||(i%43200==s%43200)) f2=false;
    }
    else
    {
        for(int i=t1+1;i<t2+43200;i++)
             if((i%43200==h%43200)||(i%43200==m%43200)||(i%43200==s%43200)) f1=false;
        for(int i=t1-1;i>t2;i--)
             if((i%43200==h%43200)||(i%43200==m%43200)||(i%43200==s%43200)) f2=false;
    }
    if(f1||f2) printf("YES\n"); else printf("NO\n");
    return 0;
}