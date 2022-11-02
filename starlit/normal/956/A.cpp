#include<bits/stdc++.h>
#define N 55
int n,m,c1,c2;
char mp[N][N];
bool test[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
    scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
    if(!test[i])
    {
        for(int j=i+1;j<n;j++)
        {
            c1=c2=0;
            for(int k=0;k<m;k++)
            {
                c1+=(mp[i][k]=='#')&&(mp[j][k]=='#'),
                c2+=(mp[i][k]=='#')^(mp[j][k]=='#');
            }
            if(c1)
            {
                if(c2)return puts("No"),0;
                test[j]=1;
            }
        }
    }
    puts("Yes");
}