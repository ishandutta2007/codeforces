#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int start=0;
    int be=a[0];
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==a[i-1] || i==n)
        {
            int len=i-start;
            ans=max(ans,(len-1)/2);
            if (len%2==0)
            {
                int k=len/2;
                for (int j=start;j<start+k;j++)
                    a[j]=be;
                for (int j=start+k;j<start+len;j++)
                    a[j]=1-be;
            }
            else
            {
                for (int j=start;j<start+len;j++)
                    a[j]=be;
            }
            be=a[i];
            start=i;

        }
    }
    printf("%d\n",ans);
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}