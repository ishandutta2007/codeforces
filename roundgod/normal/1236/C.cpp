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
vector<int> v[MAXN];
int main()
{
    scanf("%d",&n);
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tot++;
            if(i&1) v[j].push_back(tot); else v[n-j+1].push_back(tot);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto x:v[i]) printf("%d ",x);
        puts("");
    }
    return 0;
}