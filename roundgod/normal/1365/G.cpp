#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v;
ll ans[15];
ll ask(vector<int> &v)
{
    if(!(int)v.size()) return 0;
    printf("? %d",(int)v.size());
    for(auto x:v) printf(" %d",x);
    printf("\n");
    fflush(stdout);
    ll x; scanf("%lld",&x);
    return x;
}
int main()
{
    for(int i=0;i<(1<<13);i++)
    {
        int cnt=0;
        for(int j=0;j<13;j++) if(i&(1<<j)) cnt++;
        if(cnt==7) v.push_back(i);
    }
    scanf("%d",&n);
    for(int i=0;i<13;i++)
    {
        vector<int> tmp;
        for(int j=0;j<n;j++)
            if(v[j]&(1<<i)) tmp.push_back(j+1);
        ans[i]=ask(tmp);
    }
    printf("!");
    for(int i=0;i<n;i++)
    {
        ll res=0;
        for(int j=0;j<13;j++)
            if(!(v[i]&(1<<j))) res|=ans[j];
        printf(" %lld",res);
    }
    printf("\n");
    fflush(stdout);
    return 0;
}