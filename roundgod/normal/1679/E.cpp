#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM (1<<17)
#define MAXQ 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int query[MAXQ];
int sum[MAXN];
int f[18][MAXM];
string str,t;
int pw[18][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    for(int i=1;i<=17;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=1000;j++) pw[i][j]=1LL*i*pw[i][j-1]%MOD;
    }
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(i>0) sum[i]=sum[i-1];
        if(str[i]=='?') sum[i]++;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int mask=0;
        cin>>t;
        for(int j=0;j<(int)t.size();j++) mask|=(1<<(t[j]-'a'));
        query[i]=mask;
    }
    for(int i=0;i<2*n-1;i++)
    {
        int cnt=0;
        int nmask=0;
        int l,r;
        if(i<n)
        {
            l=r=i;
            if(str[i]=='?') cnt=1;
        }
        else 
        {
            l=i-n; r=i-n+1;
            if(l>=0&&r<n)
            {
                if(str[l]=='?'&&str[r]=='?') cnt++;
                else if(str[l]=='?') nmask|=(1<<(str[r]-'a'));
                else if(str[r]=='?') nmask|=(1<<(str[l]-'a'));
                else if(str[l]!=str[r]) continue;
            }
        }
        do
        {
            for(int j=1;j<=17;j++)
            {
                int num=pw[j][cnt+sum[n-1]-sum[r]+(l==0?0:sum[l-1])];
                add(f[j][nmask],num);
            }
            l--; r++;
            if(l>=0&&r<n)
            {
                if(str[l]=='?'&&str[r]=='?') cnt++;
                else if(str[l]=='?') nmask|=(1<<(str[r]-'a'));
                else if(str[r]=='?') nmask|=(1<<(str[l]-'a'));
                else if(str[l]!=str[r]) break;
            }
        }while(l>=0&&r<n);
    }
    for(int i=1;i<=17;i++)
    {
        for(int j=0;j<17;j++)
            for(int mask=0;mask<(1<<17);mask++)
                if(mask&(1<<j)) add(f[i][mask],f[i][mask^(1<<j)]);
    }
    for(int i=0;i<q;i++) 
    {
        int cnt=__builtin_popcount(query[i]);
        printf("%d\n",f[cnt][query[i]]);
    }
    return 0;
}