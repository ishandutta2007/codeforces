#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#define ll long long

using namespace std;
const ll inf=4294967296;

int main()
{
    int t,n,flag=0;
    scanf("%d",&t);
    char ch[10];
    ll loop=1;
    ll ans=0;
    stack<int >S;
    while(t--)
    {
        cin>>ch;
        if(ch[0]=='a')
        {
            ans+=loop;
            if(ans>=inf)
                flag=1;
        }
        else if(ch[0]=='f')
        {
            cin>>n;
            if(loop>=inf)
                S.push(1);
            else
                S.push(n),loop=loop*n;
        }
        else
        {
            if(!S.empty())
            {
 
                int k=S.top();
                loop/=k;
                S.pop();
            }
        }
    }
    if(flag)
        cout<<"OVERFLOW!!!"<<endl;
    else
        cout<<ans<<endl;
	return 0;
}