#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int tot=1;
int trie[MAXM][2],num[MAXM];
void insert(int val,int pos)
{
    int rt=1;
    for(int i=pos;i>=0;i--)
    {
        int x=(a[val]>>i)&1;
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
    }
    num[rt]=val;
}
int find_max(int val,int pos)
{
    int rt=1;
    for(int i=pos;i>=0;i--)
    {
        int x=(a[val]>>i)&1;
        if(trie[rt][x^1]) rt=trie[rt][x^1]; else rt=trie[rt][x];
    }
    return num[rt];
}
void clear()
{
    for(int i=1;i<=tot;i++) num[i]=trie[i][0]=trie[i][1]=0;
    tot=1;
}
vector<int> solve(vector<int> &id,int pos)
{
    if(pos==-1||id.size()<=1) return id;
    vector<int> zero,one;
    for(auto x:id) if(a[x]&(1<<pos)) one.push_back(x); else zero.push_back(x);
    if(k&(1<<pos))
    {
        clear();
        if(one.size()&&zero.size())
        {
            for(auto x:one) insert(x,pos);
            for(auto x:zero) 
            if((a[find_max(x,pos)]^a[x])>=k)
            {
                vector<int> v;
                v.push_back(x); v.push_back(find_max(x,pos));
                return v;
            }
        }
        if(one.size())
        {
            vector<int> v;
            v.push_back(one.back()); return v;
        }
        if(zero.size())
        {
            vector<int> v;
            v.push_back(zero.back()); return v;
        }
        return vector<int>{};
    }
    else
    {
        vector<int> lhs=solve(zero,pos-1); vector<int> rhs=solve(one,pos-1);
        for(auto x:rhs) lhs.push_back(x);
        return lhs;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<int> id;
    for(int i=1;i<=n;i++) id.push_back(i);
    auto ans=solve(id,29);
    if(ans.size()<=1) puts("-1");
    else
    {
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}