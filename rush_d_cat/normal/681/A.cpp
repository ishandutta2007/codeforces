#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    string s;int a,b;
    int n;cin>>n;
    bool flag = false;
    while(n--)
    {
        cin>>s>>a>>b;
        if((a>=2400)&&(b>a)) flag=true;
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}