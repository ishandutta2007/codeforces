#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
char a[5005];
int aa[26][26][5005];
signed main()
{
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++)a[i]-=97;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            aa[a[i]][a[(i+j)%n]][j]++;
        }
    }
    int ans=0;
    for(int i=0;i<26;i++)
    {
        int wew=0,pop=0;
        for(int j=0;j<n;j++)
        {
            wew=0;
            for(int k=0;k<26;k++)if(aa[i][k][j]==1)wew++;
            //if(aa[a[i]][a[(i+j)%n]][j]==1){ans++;printf("%lld %lld\n",i,j);break;}
            pop=pop>wew?pop:wew;
        }
        ans+=pop;
    }
    printf("%.7lf\n",1.0*ans/n);
    //if charm 1 than shutdown -s -f -t 0000 on charm's computer.

}