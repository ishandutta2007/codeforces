#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;
typedef __int64 ll;
typedef pair<int,int> P;
int main()
{
    int n;cin>>n;
    char s[12];cin>>s;
    bool ok[10][10];
    memset(ok,0,sizeof(ok));
    int x[10]={4,1,1,1,2,2,2,3,3,3};
    int y[10]={2,1,2,3,1,2,3,1,2,3};
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            ok[i][j]=1;
        }
    }
    ok[4][2]=1;
    P p[12];
    bool res=1;
    for(int i=0;i<n-1;i++)
    {
        p[i].first=x[s[i+1]-'0']-x[s[i]-'0'];
        p[i].second=y[s[i+1]-'0']-y[s[i]-'0'];
    }
    for(int i=0;i<=9;i++)
    {
        if(i==s[0]-'0') continue;
        int x_=x[i],y_=y[i];
        bool work=1;
        for(int j=0;j<n-1;j++)
        {
            x_+=p[j].first;
            y_+=p[j].second;
            work&=ok[x_][y_];
        }
        if(work){
            res=0;
        }
    }
    if(res) cout<<"YES";
    else cout<<"NO";
    return 0;
}