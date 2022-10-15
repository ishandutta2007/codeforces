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
vector<P> states,ans;
int main()
{
    scanf("%d",&n);
    if(n==1) {puts("1\n1 1"); return 0;}
    int d=(n+1)/3;
    int ans=n-d;
    printf("%d\n",ans);
    for(int i=0;i<d;i++) printf("%d %d\n",1+2*i,1+i);
    for(int i=0;i<d-1;i++) printf("%d %d\n",2+2*i,1+d+i);
    for(int i=3*d;i<=n;i++) printf("%d %d\n",i,i);
    return 0;
}