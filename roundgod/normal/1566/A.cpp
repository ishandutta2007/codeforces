#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&s);
        printf("%d\n",s/(n/2+1));
    }
    return 0;
}