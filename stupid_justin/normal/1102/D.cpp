#include<bits/stdc++.h>
using namespace std;
char s[300010];
int num[3];
int b[3];
int ans[300010];
int tot;
int main()
{
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;s[i];i++)
    {
        num[s[i]-'0']++;
    }
    for(int i=0;i<=2;i++)
    {
        b[i]=num[i]-n/3;
    }
    for(int i=0;i<=2;i++)
    {
        if(b[i]<0)
        {
            while(b[i]<0)
            {
                ans[++tot]=i;
                b[i]++;
            }
        }
    }
    int now=0;
    for(int i=0;s[i];i++)
    {
        int intttt=s[i]-'0';
        if(b[intttt]>0&&( intttt>ans[now+1]||b[intttt]==num[intttt] ) )
        {
            s[i]=ans[++now]+'0';
            b[intttt]--;
        }
        num[intttt]--;
        if(now==tot)
          break;
    }
    cout<<s<<endl;
}