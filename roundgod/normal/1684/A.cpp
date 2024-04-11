#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        if(n==2)
        {
            printf("%d\n",str[1]-'0');
            continue;
        }
        int ans=10;
        for(int i=0;i<n;i++) ans=min(ans,str[i]-'0');
        printf("%d\n",ans);
    }
    return 0;
}