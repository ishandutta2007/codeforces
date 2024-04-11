#include<bits/stdc++.h>
#define MAXN 2505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
vector<int> op;
int t;
void reverse_interval(int l,int r)//both l and r odd
{
    if(l==r) return;
    assert(l&1); assert(r&1);
    op.push_back(r);
    op.push_back(r-l+1);
    op.push_back(r);
    reverse(a+l,a+r+1);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool f=true;
        for(int i=1;i<=n;i++) if((a[i]&1)!=(i&1)) {f=false;}
        if(!f) {puts("-1"); continue;}
        op.clear();
        for(int i=1;i*2<=n;i++)
        {
            int x,y;
            for(int j=1;j<=n;j++) if(a[j]==2*i-1) x=j;
            op.push_back(x);
            reverse(a+1,a+x+1);//2i-1 on top         
            for(int j=1;j<=n;j++) if(a[j]==2*i) x=j;
            op.push_back(x-1);//2i-1 2i 
            reverse(a+1,a+x);
            reverse_interval(x-1,n-2*(i-1));
        }
        op.push_back(n);
        reverse(a+1,a+n+1);
        printf("%d\n",(int)op.size());
        for(auto x:op) printf("%d ",x);
        puts("");
    }
    return 0;
}