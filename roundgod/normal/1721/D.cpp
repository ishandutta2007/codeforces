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
int t,n,a[MAXN],b[MAXN];
int solve(vector<vector<int> > &a,vector<vector<int> > &b,int dig)
{
    if(dig<0) return 0;
    bool f=true;
    for(int i=0;i<(int)a.size();i++)
    {
        int cnt0=0,cnt1=0;
        for(auto x:a[i]) if(x&(1<<dig)) cnt1++;
        for(auto x:b[i]) if(!(x&(1<<dig))) cnt0++;
        if(cnt0!=cnt1) {f=false; break;}
    }
    if(!f) return solve(a,b,dig-1);
    else
    {
        if(dig==0) return 1;
        vector<vector<int> > ta,tb;
        for(int i=0;i<(int)a.size();i++)
        {
            vector<int> azero,aone,bzero,bone;
            for(auto x:a[i]) if(x&(1<<dig)) aone.push_back(x); else azero.push_back(x);
            for(auto x:b[i]) if(x&(1<<dig)) bone.push_back(x); else bzero.push_back(x);
            if(aone.size()) {ta.push_back(aone); tb.push_back(bzero);}
            if(azero.size()) {ta.push_back(azero); tb.push_back(bone);}
        }
        return solve(ta,tb,dig-1)+(1<<dig);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        vector<vector<int>> a,b;
        a.clear(); a.resize(1); b.clear(); b.resize(1);
        for(int i=1;i<=n;i++) 
        {
            int x;
            scanf("%d",&x); a[0].push_back(x);
        }
        for(int i=1;i<=n;i++) 
        {
            int x;
            scanf("%d",&x); b[0].push_back(x);
        }
        printf("%d\n",solve(a,b,29));
    }
    return 0;
}