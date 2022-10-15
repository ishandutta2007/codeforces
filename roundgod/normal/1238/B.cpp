#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,r;
vector<int> v;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&r); v.clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int sz=(int)v.size();
        int lb=0,rb=sz;
        while(rb-lb>1)
        {
            int mid=(lb+rb)/2;
            if(mid>=sz||v[sz-1-mid]-1LL*mid*r<=0) rb=mid; else lb=mid;
        }
        printf("%d\n",rb);
    }
    return 0;
}