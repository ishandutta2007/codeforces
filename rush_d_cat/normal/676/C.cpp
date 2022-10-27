#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;
int n,k,a=0,b=0,st=0,ans=0;
char s[maxn];
int main()
{
    cin>>n>>k>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') a++;
        else b++;

        if(min(a,b)>k)
        {
            if(s[st]=='a') a--;
            else b--;
            st++;
        }
        else
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}