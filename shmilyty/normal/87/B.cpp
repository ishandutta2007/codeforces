#include <bits/stdc++.h>
using namespace std;
const int maxn=500010;
int n,ans,tmp,cnt;
int a[maxn],c[maxn];
char s[maxn],ss[maxn],sss[maxn];
map<string,int>mp;
string str1,str2;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        mp["void"]=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(strcmp(s,"typedef")==0)
            {
                scanf("%s %s",ss,sss);
                int l=strlen(ss);
                int ans=0,cnt=0;
                str1="";
                for(int i=0;i<l;i++)
                {
                    if(ss[i]=='&') ans--;
                    else if(ss[i]=='*') ans++;
                    else str1+=ss[i];
                }
                cnt=mp[str1];
                if(cnt>0) cnt+=ans;
                else cnt=0;
                mp[(string)sss]=cnt;
            }
            else
            {
                scanf("%s",ss);
                int l=strlen(ss);
                int ans=0,cnt=0;
                str1="";
                for(int i=0;i<l;i++)
                {
                    if(ss[i]=='&') ans--;
                    else if(ss[i]=='*') ans++;
                    else str1+=ss[i];
                }
                cnt=mp[str1];
                if(cnt>0) cnt+=ans;
                else cnt=0;
                if(cnt<=0) puts("errtype");
                else
                {
                    printf("void");
                    for(int i=1;i<cnt;i++)
                    printf("*");
                    puts("");
                }
            }
        }
    }
    return 0;
}