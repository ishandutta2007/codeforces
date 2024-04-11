/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-12 19:29:34
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
int n,p;
string str;
int main()
{
    scanf("%d%d",&n,&p);
    cin>>str;
    bool flag=false;
    for(int i=0;i<p;i++)
    {
        int now=i,f1=0,f2=0,f3=0;
        while(now<n)
        {
            if(str[now]=='1') f1=1;
            if(str[now]=='0') f2=1;
            if(str[now]=='.') f3++;
            now+=p;
        }
        if(f1+f2+f3>=2)
        {
            int cnt=0;
            for(int j=i;j<n;j+=p)
            {
                if(str[j]=='.')
                {
                    if(f1) str[now]='0'; 
                    else if(f2) str[j]='1';
                    else 
                    {
                        str[j]='0'+cnt;
                        cnt^=1;
                    }
                }
            }
            flag=true;
            break;
        }
    }
    if(!flag) puts("No");
    else
    {
        for(int i=0;i<n;i++)
            if(str[i]=='.') str[i]='0';
        cout<<str<<endl;
    }
    return 0;
}