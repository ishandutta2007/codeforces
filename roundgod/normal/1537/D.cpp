#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first 
#define S second
#define x1 daksida 
#define y1 daskdsia
#define x2 doakdos
#define y2 dakoda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool win[605];
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==1)
        {
            puts("Bob");
        }
        else if(__builtin_popcount(n)==1)
        {
            int t=0;
            while(n%2==0) n>>=1,t++;
            if(t%2==1) puts("Bob"); else puts("Alice");
        }
        else puts("Alice");
    }
    return 0;
}