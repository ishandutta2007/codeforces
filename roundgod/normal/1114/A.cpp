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
int x,y,z,a,b,c;
int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    if(a<x||a+b<x+y||a+b+c<x+y+z) puts("NO"); else puts("YES");
    return 0;
}