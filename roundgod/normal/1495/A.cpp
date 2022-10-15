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
vector<int> a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a.clear(); b.clear();
        for(int i=0;i<2*n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==0) a.push_back(max(-y,y));
            else b.push_back(max(-x,x));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        double ans=0.0;
        for(int i=0;i<n;i++) ans+=sqrt((double)1.0*a[i]*a[i]+(double)1.0*b[i]*b[i]);
        printf("%.15f\n",ans);
    }
    return 0;
}