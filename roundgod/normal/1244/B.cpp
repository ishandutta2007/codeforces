#include<bits/stdc++.h>
#define MAXN 250005
#define MAXLOGN 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1')
            {
                ans=max(ans,2*(i+1));
                ans=max(ans,2*(n-i));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}