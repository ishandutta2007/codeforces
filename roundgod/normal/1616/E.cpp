#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define INF2 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n;
string s,t;
vector<int> pos[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        cin>>s; cin>>t;
        ll ans=INF;
        for(int i=0;i<26;i++) pos[i].clear();
        for(int i=0;i<n;i++) pos[s[i]-'a'].push_back(i);
        for(int i=0;i<26;i++) reverse(pos[i].begin(),pos[i].end());
        for(int i=1;i<=n;i++) bit[i]=0;
        ll inv=0;
        for(int i=0;i<n;i++)
        {
            int id=t[i]-'a';
            int smaller=INF2,eq=INF2;
            for(int j=0;j<id;j++)
            {
                if(pos[j].size()) smaller=min(smaller,pos[j].back());
            }
            if(smaller!=INF2) 
            {
                ans=min(ans,inv+smaller-sum(smaller+1));
            }
            if(pos[id].size()) eq=pos[id].back(); else break;
            inv+=eq-sum(eq+1);
            add(eq+1,1);
            pos[id].pop_back();
        }
        if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    }
    return 0;
}