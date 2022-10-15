#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
int n;
char str[MAXN];
bool a[26];
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    int cnt=0,ans=0;
    memset(a,false,sizeof(a));
    for(int i=0;i<n;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            memset(a,false,sizeof(a));
            cnt=0;
        }
        else
        {
            if(!a[(int)str[i]-97])
            {
                a[(int)str[i]-97]=true;
                cnt++;
                ans=max(ans,cnt);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}