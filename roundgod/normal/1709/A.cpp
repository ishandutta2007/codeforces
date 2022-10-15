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
int t,x,a[4];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x,&a[1],&a[2],&a[3]);
        if(a[x]&&a[a[x]]) puts("YES"); else puts("NO");
    }
    return 0;
}