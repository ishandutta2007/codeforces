#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char a[300000+2],c;
int n,m,cnt=0,t=0,num=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]=='.') cnt++;
        if(a[i]=='.'&&a[i-1]!='.') num++;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t>>c;
        if(c=='.'&&a[t]!='.')
        {
            cnt++;a[t]=c;
            if(a[t-1]=='.'&&a[t+1]=='.')
            {
                num--;
            }
            if(a[t-1]!='.'&&a[t+1]!='.')
            {
                num++;
            }
            cout<<cnt-num<<endl;
        }
        else
        if(c!='.'&&a[t]=='.')
        {
            cnt--;a[t]=c;
            if(a[t-1]=='.'&&a[t+1]=='.')
            {
                num++;
            }
            if(a[t-1]!='.'&&a[t+1]!='.')
            {
                num--;
            }
            cout<<cnt-num<<endl;
        }
        else
        {
            cout<<cnt-num<<endl;
        }
    }
    return 0;
}