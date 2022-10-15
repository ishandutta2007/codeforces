#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define INV 500000004
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k;
string s,t,str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int p2[MAXN],invp2[MAXN];
int sum[MAXN][26];
int solve(string tt,int l,int r)
{
    if(l>r) return 0;
    if((int)tt.size()==1)
    {
        int x=tt[0]-'a',sz=(int)t.size();
        int ans=sum[sz-l][x];
        dec(ans,sum[sz-1-r][x]);
        ans=1LL*ans*invp2[sz-1-r]%MOD;
        return ans;
    }
    int ans=0;
    bool f=true;
    for(int i=0;i<(int)tt.size();i+=2) if(tt[i]!=t[l]) {f=false; break;}
    if(f) 
    {
        string tmp="";
        for(int i=1;i<(int)tt.size();i+=2) tmp+=tt[i];
        add(ans,solve(tmp,l+1,r));
    }
    f=true;
    for(int i=1;i<(int)tt.size();i+=2) if(tt[i]!=t[l]) {f=false; break;}
    if(f) 
    {
        string tmp="";
        for(int i=0;i<(int)tt.size();i+=2) tmp+=tt[i];
        add(ans,solve(tmp,l+1,r));
    }
    return ans;
}
int main()
{
    p2[0]=invp2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=100000;i++) invp2[i]=1LL*invp2[i-1]*INV%MOD;
    scanf("%d%d",&n,&q);
    cin>>s; cin>>t;
    for(int i=0;i<26;i++) sum[0][i]=0;
    int x=1,sz=(int)t.size();
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<26;j++) sum[i+1][j]=sum[i][j];
        add(sum[i+1][(t[sz-1-i]-'a')],x);
        x=2LL*x%MOD;
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d",&k);
        cin>>str;
        n=(int)str.size();
        int ans=0;
        for(int j=0;j<=(int)s.size();j++)
        {
            int now=j;
            bool f=true;
            string tt="";
            for(int kk=0;kk<n;kk++)
            {
                if(now!=s.size())
                {
                    if(str[kk]!=s[now])
                    {
                        f=false;
                        break;
                    }
                }
                else tt+=str[kk];
                now++;
                if(now>s.size()) now=0;
            }
            if(f)
            {
                if(tt=="") add(ans,p2[k]);
                else add(ans,solve(tt,0,k-1));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}