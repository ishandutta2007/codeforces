#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a,b,n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&n);
        int cnt=0;
        while(a<=n&&b<=n)
        {
            if(a>b) swap(a,b);
            a+=b;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}