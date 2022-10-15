#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> v;
vector<int> sum;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        sum.clear();
        int last=-1,cnt=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if(x==last||last==-1) cnt++;
            else
            {
                v.push_back(cnt);
                cnt=1;
            }
            last=x;
        }
        v.push_back(cnt);
        sum.push_back(0);
        for(int i=0;i<(int)v.size();i++) sum.push_back(sum.back()+v[i]);
        int gold=v[0],silver=0,bronze=0;
        int s=0;
        int lastpos=0;
        for(int i=0;i<n;i++)
        {
            s+=v[i];
            if(s*2>n) {lastpos=i-1; break;}
        }
        bool f=false;
        for(int i=1;i<lastpos;i++)
        {
            if(sum[i+1]-v[0]>v[0]&&sum[lastpos+1]-sum[i+1]>v[0])
            {
                silver=sum[i+1]-v[0];
                bronze=sum[lastpos+1]-sum[i+1];
                f=true;
                break;
            }
        }
        if(!f) puts("0 0 0"); else printf("%d %d %d\n",gold,silver,bronze);
    }
    return 0;
}