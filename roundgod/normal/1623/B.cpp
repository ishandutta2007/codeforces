#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,l,r;
set<P> s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s.clear();
        for(int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            s.insert(P(l,r));
        }
        for(auto p:s)
        {
            if(p.F==p.S) printf("%d %d %d\n",p.F,p.S,p.S);
            else
            {
                for(int i=p.F;i<=p.S;i++)
                {
                    bool f=true;
                    if(i!=p.F&&!s.count(P(p.F,i-1))) f=false;
                    if(i!=p.S&&!s.count(P(i+1,p.S))) f=false;
                    if(f) 
                    {
                        printf("%d %d %d\n",p.F,p.S,i);
                        break;
                    }
                }
            }
        }
    }
}