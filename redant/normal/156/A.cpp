#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("in1.in","r",stdin);
    char s[2002], t[2002];
    scanf("%s %s",s,t);
    int sn = strlen(s), st = strlen(t);
    int ans = st;
    for(int i=-st;i<sn;i++)
    {
        int cur = 0;
        for(int j=0;j<st;j++)
            if((i+j<0||i+j>=sn) || s[i+j]!=t[j]) cur++;
        ans = min(ans,cur);
    }
    printf("%d\n",ans);
    return 0;
}