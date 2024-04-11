#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll k;
int cnt[15];
string str="codeforces";
int main()
{
    scanf("%lld",&k);
    ll ans=1;
    int cur=1;
    for(int i=1;i<=10;i++) cnt[i]=1;
    while(ans<k)
    {
        for(int i=1;i<=10;i++) 
        {
            cnt[i]=cur+1;
            ans=ans/cur*(cur+1);
            if(ans>=k) break;
        }
        cur++;
    }
    for(int i=0;i<10;i++)
        for(int j=0;j<cnt[i+1];j++) 
            printf("%c",str[i]);
    return 0;
}