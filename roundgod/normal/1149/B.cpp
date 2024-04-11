#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,q;
string str;
int nxt[MAXN][26];
int dp[255][255][255];
vector<int> a[3];
int id[3];
string s[3];
void update_dp(int i,int j,int k)
{
    if(i<(int)s[0].size()) dp[i+1][j][k]=min(dp[i+1][j][k],nxt[dp[i][j][k]+1][s[0][i]-'a']);
    if(j<(int)s[1].size()) dp[i][j+1][k]=min(dp[i][j+1][k],nxt[dp[i][j][k]+1][s[1][j]-'a']);
    if(k<(int)s[2].size()) dp[i][j][k+1]=min(dp[i][j][k+1],nxt[dp[i][j][k]+1][s[2][k]-'a']);
}
void append(int type,char ch)
{
    type--;
    s[type]+=ch;
    if(type==0)
    {
        for(int i=(int)s[0].size()-1;i<=(int)s[0].size();i++)
            for(int j=0;j<=(int)s[1].size();j++)
                for(int k=0;k<=(int)s[2].size();k++)
                    update_dp(i,j,k);
    }
    else if(type==1)
    {
        for(int i=0;i<=(int)s[0].size();i++)
            for(int j=(int)s[1].size()-1;j<=(int)s[1].size();j++)
                for(int k=0;k<=(int)s[2].size();k++)
                    update_dp(i,j,k);
    }
    else
    {
        for(int i=0;i<=(int)s[0].size();i++)
            for(int j=0;j<=(int)s[1].size();j++)
                for(int k=(int)s[2].size()-1;k<=(int)s[2].size();k++)
                    update_dp(i,j,k);
    }
}
void init()
{
    for(int i=0;i<26;i++) nxt[n][i]=nxt[n+1][i]=n;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
        {
            if(str[i]==(int)'a'+j) nxt[i][j]=i;
            else nxt[i][j]=nxt[i+1][j];
        }
    }
    for(int i=0;i<=250;i++)
        for(int j=0;j<=250;j++)
            for(int k=0;k<=250;k++)
                dp[i][j][k]=INF;
    dp[0][0][0]=-1;
}
void del(int type)
{
    type--;
    if(type==0)
    {
        int i=(int)s[0].size();
        for(int j=0;j<=(int)s[1].size();j++)
            for(int k=0;k<=(int)s[2].size();k++)
                dp[i][j][k]=INF;
    }
    else if(type==1)
    {
        int j=(int)s[1].size();
        for(int i=0;i<=(int)s[0].size();i++)
            for(int k=0;k<=(int)s[2].size();k++)
                dp[i][j][k]=INF;
    }
    else
    {
        int k=(int)s[2].size();
        for(int i=0;i<=(int)s[0].size();i++)
            for(int j=0;j<=(int)s[1].size();j++)
                dp[i][j][k]=INF;
    }
    int sz=(int)s[type].size();
    s[type]=s[type].substr(0,sz-1);
}
bool check()
{
    int i=(int)s[0].size(),j=(int)s[1].size(),k=(int)s[2].size();
    return dp[i][j][k]<n;
}
char que[3],ch[3];
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    init();
    for(int i=0;i<q;i++)
    {
        int type;
        scanf("%s %d",que,&type);
        if(que[0]=='+') 
        {
            scanf("%s",ch);
            append(type,ch[0]);
        }
        else
        {
            del(type);
        }
        if(check()) puts("YES"); else puts("NO");
    }
    return 0;
}