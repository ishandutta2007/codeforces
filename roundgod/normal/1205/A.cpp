#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN];
int main()
{
    scanf("%d",&n);
    if(n%2==0) puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            a[i]=2*i-1; a[i+n]=2*i;
            if(i&1) swap(a[i],a[i+n]);
        }
        for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
    }
}