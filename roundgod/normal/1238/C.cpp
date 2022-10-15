#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,h,n;
vector<int> v;
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&h,&n);
        v.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        reverse(v.begin(),v.end());
        int ans=0;
        while(v.size()>1)
        {
            int sz=(int)v.size();
            if(v[sz-1]!=v[sz-2]+1) v[sz-1]=v[sz-2]+1;
            if(v.size()>2)
            {
                if(v[sz-3]==v[sz-2]-1)
                {
                    v.pop_back();
                    v.pop_back();
                    continue;
                }
                else
                {
                    ans++;
                    v.pop_back();
                    v.pop_back();
                    v.push_back(v.back()+1);
                }
            }
            else
            {
                if(v[sz-2]!=1) ans++;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}