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
bool del[27];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(del,false,sizeof(del));
        scanf("%d",&n);
        cin>>str;
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            string ss;
            cin>>ss;
            del[ss[0]-'a']=true;
        }
        int last=0; 
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            if(del[str[i]-'a'])
            {
                ans=max(ans,i-last);
                last=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}