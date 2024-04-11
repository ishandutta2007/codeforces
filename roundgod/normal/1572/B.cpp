#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> v,ans;
void go(int x)
{
    ans.push_back(x);
    a[x]=a[x+1]=a[x+2]=(a[x]^a[x+1]^a[x+2]);
}
void solve(int now)
{
    if(now>=n-1) return;
    if(!a[now+1]) {solve(now+1); return;}
    if(a[now+2]) {go(now); solve(now+1); return;}
    if(a[now+3]) {go(now+1); solve(now+1); return;}
    go(now+1); go(now); solve(now+1); return;
}
void print()
{
    puts("YES");
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    puts("");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        v.clear(); ans.clear();
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            s^=a[i];
            if(a[i]) v.push_back(i);
        }
        if(s==1) {puts("NO"); continue;}
        if(!a[1]) {solve(1); print(); continue;}
        int now=1;
        while(now<n-1)
        {
            if(a[now+1]&&a[now+2]) {now+=2; continue;}
            if(a[now+1]^a[now+2]) {go(now); break;} 
            go(now); now+=2;
        }
        if(now>=n-1) {puts("NO"); continue;}
        for(int i=now;i-2>=1;i-=2) go(i-2);
        solve(now);
        print();
    }
    return 0;
}