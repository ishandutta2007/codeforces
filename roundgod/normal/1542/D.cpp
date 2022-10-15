#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
vector<int> v;
string str;
int f[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        if(str[0]=='-') v.push_back(0);
        else 
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
        {
            memset(f,0,sizeof(f));
            f[0][0]=1;
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    if(!f[j][k]) continue;
                    add(f[j+1][k],f[j][k]);
                    if(v[j]==0)
                    {
                        if(k==0) add(f[j+1][k],f[j][k]); else add(f[j+1][k-1],f[j][k]);
                    }
                    else if(v[j]<=v[i]) add(f[j+1][k+1],f[j][k]);
                    else add(f[j+1][k],f[j][k]);
                }
            }
            for(int k=0;k<=i+1;k++) f[i+1][k]=f[i][k];
            for(int j=i+1;j<n;j++)
                for(int k=0;k<=j;k++)
                {
                    if(!f[j][k]) continue;
                    add(f[j+1][k],f[j][k]);
                    if(v[j]==0)
                    {
                        if(k)add(f[j+1][k-1],f[j][k]);
                    }
                    else if(v[j]<v[i]) add(f[j+1][k+1],f[j][k]);
                    else add(f[j+1][k],f[j][k]);
                }
            for(int j=0;j<=n;j++) add(ans,1LL*v[i]*f[n][j]%MOD);
        }
    }
    printf("%d\n",ans);
    return 0;
}