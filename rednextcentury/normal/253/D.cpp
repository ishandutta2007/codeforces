#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
int b[401][401][26];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    getchar();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=getchar();
            for (int x=0;x<26;x++)b[i][j][x]=b[i][j-1][x];
            b[i][j][a[i][j]-'a']++;
        }
        getchar();
    }
    long long ans=0;
    for (int i=1;i<=m;i++)
    {
        for (int x=2;x<=i;x++)
        {
            int num=0;
            long long s[26]={0};
            int l=1,r=0;
            long long cur=0;
            while(++r<=n)
            {
                num+=b[r][i][0]-b[r][i-x][0];
                if (a[r][i]==a[r][i-x+1])
                    cur+=s[a[r][i]-'a'],s[a[r][i]-'a']++;
                while(num>k)
                {
                    num-=b[l][i][0]-b[l][i-x][0];
                    if (a[l][i]==a[l][i-x+1])
                        cur-=s[a[l][i]-'a']-1,s[a[l][i]-'a']--;
                    l++;
                }
                if (a[r][i]==a[r][i-x+1] && l<=r)
                    ans+=s[a[r][i]-'a']-1;
            }
        }
    }
    cout<<ans<<endl;
}