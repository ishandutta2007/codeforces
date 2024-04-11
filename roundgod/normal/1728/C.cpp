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
int t,n;
priority_queue<int> pqa,pqb;
int calc(int x)
{
    int cnt=0;
    while(x)
    {
        x/=10;
        cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            pqa.push(x);
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            pqb.push(x);
        }
        int ans=0;
        while(pqa.size())
        {
            int x=pqa.top(); int y=pqb.top();
            if(x==y) {pqa.pop(); pqb.pop();}
            else if(x>y)
            {
                pqa.pop();
                pqa.push(calc(x)); ans++;
            }
            else
            {
                pqb.pop(); pqb.push(calc(y)); ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}