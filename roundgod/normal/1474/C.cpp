#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<P> v;
multiset<int> ms;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        bool flag=false;
        for(int i=1;i<=2*n-1;i++)
        {
            v.clear();
            bool f=true;
            ms.clear();
            v.push_back(P(a[i],a[2*n]));
            for(int j=1;j<=2*n-1;j++) if(j!=i) ms.insert(a[j]);
            int now=a[2*n]; 
            for(int j=1;j<=n-1;j++)
            {
                auto it=prev(ms.end());
                int val=*it;
                int need=now-val;
                ms.erase(it);
                if(ms.count(need)) 
                {
                    v.push_back(P(need,val));
                    now=val;
                    ms.erase(ms.find(need));
                }
                else {f=false; break;}
            }
            if(f)
            {
                flag=true;
                puts("YES");
                printf("%d\n",a[i]+a[2*n]);
                for(auto p:v) printf("%d %d\n",p.F,p.S);
                break;
            }
        }
        if(!flag) puts("NO");
    }
    return 0;
}