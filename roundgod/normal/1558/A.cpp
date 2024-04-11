#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,a,b;
set<int> s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        s.clear();
        int n=a+b;
        for(int i=0;i<2;i++)
        {
            int x=(n+i)/2,y=n-x;
            int mini=n-min(a,x)-min(b,y);
            int maxi=n-max(a+x-n,0)-max(b+y-n,0);
            assert((maxi-mini)%2==0);
            assert(maxi>=mini);
            for(int j=mini;j<=maxi;j+=2) s.insert(j);
        }
        printf("%d\n",(int)s.size());
        for(auto x:s) printf("%d ",x);
        puts("");
    }
    return 0;
}