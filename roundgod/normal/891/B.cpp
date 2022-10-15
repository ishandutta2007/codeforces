#include<bits/stdc++.h>
#define MAXN 30
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int ord[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i].S=i;
        scanf("%d",&a[i].F);
    }
    sort(a,a+n);
    int t=a[n-1].S;
    for(int i=n-1;i>0;i--)
        a[i].S=a[i-1].S;
    a[0].S=t;
    for(int i=0;i<n;i++)
        ord[a[i].S]=a[i].F;

    for(int i=0;i<n;i++)
        printf("%d ",ord[i]);
    return 0;
}