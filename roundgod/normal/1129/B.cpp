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
    scanf("%d",&k);
    int val=1999;
    printf("%d\n",val+1);
    for(int i=1;i<=val-1;i++) printf("%d ",0);
    int rem;
    if(k%1999==0) rem=1999;
    else rem=(1999-k%1999);
    printf("%d %d\n",-rem,(k+2000*rem)/1999);
    return 0;
}