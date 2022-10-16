#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

int l[N],r[N];

vector<pair<int,int> >s[31];

int ans[31];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l[i]);
        scanf("%d",&r[i]);
        int len=r[i]-l[i]+1;
        for(int j=0;j<=30;j++)
        {
            if(len>=(1<<j))
                ans[j]++;
            else
            {
                int L=l[i]%(1<<j),R=r[i]%(1<<j);
                if(L<=R)
                    s[j].push_back({L,1}),s[j].push_back({R+1,-1});
                else
                {
                    // s[j][L]++,s[j][(1<<j)]--;
                    // s[j][0]++,s[j][R+1]--;
                    s[j].push_back({L,1});
                    s[j].push_back({(1<<j),-1});
                    s[j].push_back({0,1});
                    s[j].push_back({R+1,-1});
                }
            }
        }
    }
    for(int i=0;i<=30;i++)
    {
        int ss=0,mx=0;
        sort(s[i].begin(),s[i].end());
        int lx=-1;
        for(auto [x,y]:s[i])
        {
            if(x!=lx)
                mx=max(mx,ss);
            lx=x;
            ss+=y;
        }
        ans[i]+=mx;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int x;
        scanf("%d",&x);
        int p=__builtin_ctz(x&(-x));
        printf("%d\n",ans[p]);
    }
}