#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
string str;
int cnt[3];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>str;
        n=str.size();
        int st=0,ed=0;
        memset(cnt,0,sizeof(cnt));
        int ans=INF;
        while(ed<n)
        {
            while(ed<n&&(!cnt[0]||!cnt[1]||!cnt[2]))
            {
                cnt[str[ed]-'1']++;
                ed++;
            }
            while(st<ed&&cnt[0]&&cnt[1]&&cnt[2])
            {
                ans=min(ans,ed-st);
                cnt[str[st]-'1']--;
                st++;
            }
        }
        if(ans==INF) puts("0"); else printf("%d\n",ans);
    }
    return 0;
}