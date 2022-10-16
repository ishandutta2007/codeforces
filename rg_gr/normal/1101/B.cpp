#include <string.h>
#include <stdio.h>
char a[500005];
#define ex(x) return puts("-1")&0;
signed main()
{
	scanf("%s",a);int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(i==n-3)ex(555);
        if(a[i]=='[')
        {
            for(int j=n-1;j>=i;j--)
            {
                if(j==i+2)ex(5515);
                if(a[j]==']')
                {
                    for(int k=i+1;k<j;k++)
                    {
                        if(k==j-1)ex(i*100+j*10+k);
                        if(a[k]==':')
                        {
                            for(int l=j-1;l>k;l--)
                            {
                                if(a[l]==':')
                                {
                                    int ans=4;
                                    for(int p=k+1;p<l;p++)ans+=a[p]=='|';
                                    printf("%d\n",ans);
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }ex(2);
	return 0;
}