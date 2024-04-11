#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a[MAXN];
map<int,int> cnt;
int bit[MAXN+1],n;
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
    scanf("%d",&t);
    while(t--)
    {
        cnt.clear();
        scanf("%d",&n);
        bool f=false;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++; if(cnt[a[i]]>=2) f=true;}
        if(f) {puts("YES"); continue;}
        for(int i=1;i<=n;i++) bit[i]=0;
        int cnt=0;
        for(int i=n;i>=1;i--)
        {
            if(sum(a[i]-1)&1) cnt^=1;
            add(a[i],1);
        }
        if(cnt) puts("NO"); else puts("YES");
    }
    return 0;
}