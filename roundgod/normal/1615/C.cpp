#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
string s,t;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>s;
        cin>>t;
        bool f=false;
        int cnt10=0,cnt01=0,cnt11=0,cnt00=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0'&&t[i]=='0') cnt00++;
            else if(s[i]=='0'&&t[i]=='1') cnt01++;
            else if(s[i]=='1'&&t[i]=='0') cnt10++;
            else cnt11++;
        }
        int ans=INF;
        if(cnt01==cnt10) ans=min(ans,cnt01+cnt10);
        if(cnt11>=1&&cnt11-1==cnt00) ans=min(ans,2*cnt00+1);
        if(cnt10>=1&&cnt00+1==cnt11) ans=min(ans,2*cnt11+1);
        if(ans==INF) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}