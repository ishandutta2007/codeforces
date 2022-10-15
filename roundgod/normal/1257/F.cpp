#include<bits/stdc++.h>
#define MAXN 200015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int n,a[MAXN];
map<vector<int>,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<(1<<15);i++)
    {
        vector<int> tmp;
        for(int j=2;j<=n;j++)
        {
            tmp.push_back(__builtin_popcount((a[j]&32767)^i)-__builtin_popcount((a[1]&32767)^i));
        }
        if(mp.find(tmp)==mp.end()) mp[tmp]=i;
    }
    for(int i=0;i<(1<<15);i++)
    {
        vector<int> tmp;
        for(int j=2;j<=n;j++)
        {
            tmp.push_back(__builtin_popcount((a[1]>>15)^i)-__builtin_popcount((a[j]>>15)^i));
        }
        if(mp.find(tmp)!=mp.end())
        {
            printf("%d\n",i*(1<<15)+mp[tmp]);
            return 0;
        }
    }
    puts("-1");
}