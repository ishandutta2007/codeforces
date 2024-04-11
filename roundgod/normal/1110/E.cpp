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
int n,k,a[MAXN],c[MAXN],t[MAXN];
vector<int> v1,v2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    if(c[1]!=t[1]||c[n]!=t[n])
    {
        puts("No");
        return 0;
    }
    v1.clear();v2.clear();
    for(int i=2;i<=n;i++) v1.push_back(c[i]-c[i-1]);
    for(int i=2;i<=n;i++) v2.push_back(t[i]-t[i-1]);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<n-1;i++)
    {
        if(v1[i]!=v2[i])
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}