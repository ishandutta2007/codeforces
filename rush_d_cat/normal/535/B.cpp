#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
typedef __int64 ll;
const ll inf=1000000000;
ll n,num;
ll res=0;
void dfs(ll x,ll i)
{
    if(x>=1000000000) return;
    if(res) return;
    if(x==n){res=i;return;}
    dfs(10*x+4,2*i+1);
    dfs(10*x+7,2*i+2);
}
int main()
{
    cin>>n;
    dfs(0,0);
    cout<<res<<endl;
    return 0;
}