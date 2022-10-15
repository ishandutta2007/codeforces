#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll T;
string str;
ll has[MAXN];
ll need[MAXN];
int main()
{
    scanf("%d%lld",&n,&T);
    cin>>str;
    T-=(1LL<<(str[n-1]-'a'));
    for(int i=0;i<n-1;i++)
    {
        T+=(1LL<<(str[i]-'a'));
    }
    if(T<0) {puts("No"); return 0;}
    for(int i=0;i<n-2;i++)
        has[str[i]-'a'+1]++;
    int cur=27;
    for(int i=60;i>=0;i--)
        if(T&(1LL<<i))
            need[i]=1;
    for(int i=60;i>=0;i--)
    {
        if(need[i]&&has[i]) need[i]-=min(need[i],has[i]);
        if(i) need[i-1]+=2*need[i];
    }
    if(need[0]) puts("No"); else puts("Yes");
    return 0;
}