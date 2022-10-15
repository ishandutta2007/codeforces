#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b,c;
string str;
int dp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<n;i++) if(str[i]=='w'||str[i]=='m') {puts("0"); return 0;}
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        add(dp[i+1],dp[i]);
        if(i>=1&&((str[i]=='u'&&str[i-1]=='u')||(str[i]=='n'&&str[i-1]=='n'))) add(dp[i+1],dp[i-1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}