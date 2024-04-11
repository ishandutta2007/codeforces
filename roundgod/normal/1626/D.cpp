#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],cnt[MAXN];
vector<P> v;
int val[MAXN];
int main()
{
    for(int i=0;i<18;i++)
        for(int j=(1<<i)+1;j<=min(200000,(1<<(i+1)));j++)
            val[j]=(1<<(i+1))-j;
    val[0]=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        vector<P> v;
        for(int i=1;i<=n;i++) if(cnt[i]) v.push_back(P(i,cnt[i]));
        int s=0,ans=val[n]+2;
        set<int> st;
        st.insert(0);
        for(int i=0;i<(int)v.size();i++)
        {
            if(i>=1) st.insert(s);
            s+=v[i].S;
            for(int j=0;j<18;j++)
            {
                auto it=st.lower_bound(1<<j);
                if(it!=st.end())
                {
                    if(val[n-s]+val[*it]+val[s-*it]<ans) ans=val[n-s]+val[*it]+val[s-*it];
                }
                if(it!=st.begin())
                {
                    it--;
                    if(val[n-s]+val[*it]+val[s-*it]<ans) ans=val[n-s]+val[*it]+val[s-*it];
                }
                if((1<<j)<=s)
                {
                    it=st.lower_bound(s-(1<<j));
                    if(it!=st.end())
                    {
                        if(val[n-s]+val[*it]+val[s-*it]<ans) ans=val[n-s]+val[*it]+val[s-*it];
                    }
                    if(it!=st.begin())
                    {
                        it--;
                        if(val[n-s]+val[*it]+val[s-*it]<ans) ans=val[n-s]+val[*it]+val[s-*it];
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}