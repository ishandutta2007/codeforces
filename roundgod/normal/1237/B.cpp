#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v;
bool out[MAXN];
int main()
{
    scanf("%d",&n);
    int ans=0;
    memset(out,false,sizeof(out));
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    reverse(v.begin(),v.end());
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        while(out[v.back()]) v.pop_back();
        if(v.back()!=x) ans++;
        out[x]=true;
    }
    printf("%d\n",ans);
    return 0;
}