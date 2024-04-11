#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        cin>>str;
        int ans=a*n;
        if(b>=0) ans+=b*n;
        else
        {
            int cnt=1;
            for(int i=1;i<n;i++) if(str[i]!=str[i-1]) cnt++;
            ans+=(cnt/2+1)*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}