#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,x,y;
char s[1010];
signed main()
{
    scanf("%lld",&t);
    while(t--)
	{
        scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
        int ans=0,ans2=0;
        for(int i=0;i<n;i++)
		{
            scanf("%s",s);
            int lian=0;
            for(int j=0;j<m;j++)
			{
                if(s[j]=='.')
				{
					lian++;
					ans2+=x;
				}
                if(lian==2)
				{
					ans+=y;
					lian=0;
				}
                if(s[j]=='*')
				{
                    if(lian==1)
                        ans+=x;
                    lian=0;
                }
            }
            if(lian==1) 
				ans+=x;
        }
        printf("%lld\n",ans<ans2?ans:ans2);
    }
    return 0;
}//2