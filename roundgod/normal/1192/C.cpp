#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 65
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<string> s[15];
string str;
int n,cnt[MAXM][MAXM],cnt2[MAXM][MAXM][MAXM],ans;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int getval(char ch)
{
    if(ch>='A'&&ch<='Z') return ch-'A';
    if(ch>='a'&&ch<='z') return 26+ch-'a';
    return 52+ch-'0';
}
char getch(int val)
{
    if(val<26) return 'A'+val;
    if(val<52) return 'a'+val-26;
    return '0'+val-52;
}
void solve(int len)
{
    if(!s[len].size()) return;
    memset(cnt,0,sizeof(cnt));
    memset(cnt2,0,sizeof(cnt2));
    for(auto str:s[len])
    {
        int x=getval(str[0]),y=getval(str[len-1]);
        cnt[x][y]++;
    }
    for(int l=0;l<62;l++)
        for(int i=0;i<62;i++)
        {
            if(!cnt[i][l]) continue;
            for(int j=0;j<=i;j++)
            {
                if(!cnt[j][l]) continue;
                for(int k=0;k<=j;k++)
                {
                    if(!cnt[k][l]) continue;
                    add(cnt2[i][j][k],1LL*cnt[i][l]*cnt[j][l]%MOD*cnt[k][l]%MOD);
                }
            }
        }
    for(int i=0;i<62;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;k<=j;k++)
            {
                if(!cnt2[i][j][k]) continue;
                for(int l=0;l<=k;l++)
                {
                    int dif=1;
                    if(i!=j) dif++;
                    if(j!=k) dif++;
                    if(k!=l) dif++;
                    int mult;
                    if(dif==1) mult=1;
                    else if(dif==2)
                    {
                        if(i==j&&k==l) mult=6;
                        else mult=4;
                    }
                    else if(dif==3) mult=12;
                    else mult=24;
                    if(!cnt2[i][j][l]||!cnt2[i][k][l]||!cnt2[j][k][l]) continue;
                    add(ans,1LL*mult*cnt2[i][j][k]%MOD*cnt2[i][j][l]%MOD*cnt2[i][k][l]%MOD*cnt2[j][k][l]%MOD);
                }
            }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int len=(int)str.size();
        s[len].insert(str);
        reverse(str.begin(),str.end());
        s[len].insert(str);
    }
    ans=0;
    for(int i=3;i<=10;i++) solve(i);
    printf("%d\n",ans);
    return 0;
}