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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<(1<<n);i++)
    {
        int x=0,y=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j)) x+=a[j]; else y+=a[j];
        if((x-y)%360==0) {puts("YES"); return 0;}
    }
    puts("NO");
    return 0;
}