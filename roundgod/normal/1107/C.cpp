#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
multiset<int> ms;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    cin>>str;
    int last=-1;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]-'a'!=last)
        {
            int has=min(k,(int)ms.size());
            for(int j=0;j<has;j++)
            {
                auto it=ms.end(); it--;
                ans+=*it; ms.erase(ms.find(*it));
            }
            ms.clear();
        }
        last=str[i]-'a';
        ms.insert(a[i]);
    }
    int has=min(k,(int)ms.size());
    for(int j=0;j<has;j++)
    {
        auto it=ms.end(); it--;
        ans+=*it; ms.erase(ms.find(*it));
    }
    ms.clear();
    printf("%lld\n",ans);
    return 0;
}