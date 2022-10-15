#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,a[MAXN],b[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    int ans=0;
    for(int i=0;i<=200000;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            int turns;
            if(i<b[j]) turns=0; else turns=(i-b[j])/a[j]+1;
            turns=turns&1;
            turns=(turns+str[j-1]-'0')&1;
            if(turns) cnt++;
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
}