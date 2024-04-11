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
bool check(int x)
{
    int l=1,r=n;
    bool f=true;
    while(r>l)
    {
        if(a[l]!=a[r])
        {
            if(a[l]!=x&&a[r]!=x) return false;
            if(a[l]==x) {l++; continue;}
            else {r--;continue;}
        }
        l++; r--;
    }
    return true;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int x=-1,y=-1,l=1,r=n;
        bool f=true;
        while(r>l)
        {
            if(a[l]!=a[r])
            {
                x=a[l]; y=a[r];
                break;
            }
            l++; r--;
        }
        if(x==-1&&y==-1) {puts("YES"); continue;}
        if(check(x)||check(y)) puts("YES"); else puts("NO");
    }
}