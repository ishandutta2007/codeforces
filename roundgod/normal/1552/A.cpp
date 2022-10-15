#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
char a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",a);
        for(int i=0;i<n;i++) b[i]=a[i];
        sort(b,b+n);
        int ans=0;
        for(int i=0;i<n;i++) if(a[i]!=b[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}