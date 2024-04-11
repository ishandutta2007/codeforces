#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
typedef pair<long long,int> pii;
long long go[1000010],l[1000010],r[1000010];
pii x[1000010];
set<pii> s;
int main()
{
    int n,m,n1;
    long long t1;
    cin>>n>>m;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%I64d%I64d",&l[n1],&r[n1]);
        if(n1>1)
        {
            x[n1*2-3]=make_pair(l[n1]-r[n1-1],-n1);
            x[n1*2-2]=make_pair(r[n1]-l[n1-1],n1+1000000);
        }
    }
    for(n1=1;n1<=m;n1++)
    {
        scanf("%I64d",&t1);
        x[2*n-2+n1]=make_pair(t1,n1);
    }
    sort(x+1,x+2*n-2+m+1);
    for(n1=1;n1<=2*n-2+m;n1++)
    {
        if(x[n1].second<0)
            s.insert(make_pair(r[-x[n1].second]-l[-x[n1].second-1],-x[n1].second));
        if(x[n1].second>0&&x[n1].second<1000000)
            if(!s.empty())
            {
                go[(*s.begin()).second]=x[n1].second;
                s.erase(s.begin());
            }
        if(x[n1].second>1000000)
        {
            if(s.find(make_pair(x[n1].first,x[n1].second-1000000))!=s.end())
            {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for(n1=2;n1<=n;n1++)
        printf("%d ",go[n1]);
}