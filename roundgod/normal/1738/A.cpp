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
int t,n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) {scanf("%d",&b[i]); ans+=b[i];}
        vector<int> v1,v2;
        for(int i=1;i<=n;i++) if(a[i]==1) v1.push_back(b[i]); else v2.push_back(b[i]);
        sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
        int mini=INF;
        for(int i=0;i<(int)min(v1.size(),v2.size());i++) {ans+=v1[v1.size()-1-i]; mini=min(mini,v1[v1.size()-1-i]);}
        for(int i=0;i<(int)min(v1.size(),v2.size());i++) {ans+=v2[v2.size()-1-i]; mini=min(mini,v2[v2.size()-1-i]);}
        if(v1.size()==v2.size()) ans-=mini;
        printf("%lld\n",ans);
    }
    return 0;
}