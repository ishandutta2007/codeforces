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
string str;
ll cnt1[26],cnt2[26][26];
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<n;i++)
    {
        int x=str[i]-'a';
        for(int j=0;j<26;j++) cnt2[j][x]+=cnt1[j];
        cnt1[x]++;
    }
    ll ans=0;
    for(int i=0;i<26;i++) ans=max(ans,cnt1[i]);
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            ans=max(ans,cnt2[i][j]);
    printf("%lld\n",ans);
    return 0;
}