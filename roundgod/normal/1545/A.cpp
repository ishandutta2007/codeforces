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
vector<int> v;
multiset<P> ms;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ms.clear(); v.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            v.push_back(a[i]);
            ms.insert(P(a[i],i&1));
        }
        bool f=true;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(ms.count(P(v[i],(i+1)&1)))
            {
                ms.erase(ms.find(P(v[i],(i+1)&1)));
            }
            else {f=false; break;}
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}