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
int n,k,a[MAXN];
multiset<int> ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<30;i++) if(n&(1<<i)) ans.insert(1<<i);
    if((int)ans.size()>k) {puts("NO"); return 0;}
    while((int)ans.size()<k)
    {
        auto it=ans.end();it--;
        if(*it==1) {puts("NO"); return 0;}
        int v=*it;
        ans.erase(ans.find(v));
        ans.insert(v/2);ans.insert(v/2);
    }
    puts("YES");
    for(auto v:ans) printf("%d ",v);
    return 0;
}