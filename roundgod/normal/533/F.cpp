#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 26
#define INF 1000000000000000000LL
#define F first
#define S second
#define hash adsjisad
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int MOD[2]={993244853,998244353};
int BASE[2]={233,666};
int n,m;
string s,t;
int pw[2][MAXN];
int hash[2][2][26][MAXN];
int x[2][26],y[2][26];
vector<int> G[26];
vector<int> ans;
bool visx[26],visy[26];
int main()
{
    for(int i=0;i<2;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=200000;j++) pw[i][j]=1LL*pw[i][j-1]*BASE[i]%MOD[i];
    }
    scanf("%d%d",&n,&m);
    cin>>s; cin>>t;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<26;j++)
        {
            hash[0][i][j][0]=0;
            for(int k=0;k<n;k++) hash[0][i][j][k+1]=(1LL*hash[0][i][j][k]*BASE[i]+((s[k]=='a'+j)?1:0))%MOD[i];
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<26;j++)
        {
            hash[1][i][j][0]=0;
            for(int k=0;k<m;k++) hash[1][i][j][k+1]=(1LL*hash[1][i][j][k]*BASE[i]+((t[k]=='a'+j)?1:0))%MOD[i];
        }
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<26;j++)
            y[i][j]=hash[1][i][j][m];
    for(int i=0;i<=n-m;i++)
    {
        for(int j=0;j<2;j++)
            for(int k=0;k<26;k++)
            {
                x[j][k]=(hash[0][j][k][i+m]-1LL*hash[0][j][k][i]*pw[j][m])%MOD[j];
                if(x[j][k]<0) x[j][k]+=MOD[j];
            }
        memset(visx,false,sizeof(visx));
        memset(visy,false,sizeof(visy));
        bool f=true;
        for(int j=0;j<26;j++)
        {
            if(visx[j]) continue;
            if(x[0][j]==0&&x[1][j]==0) continue;
            bool flag=false;
            for(int k=0;k<26;k++)
            {
                if(visy[k]||visy[j]||visx[k]) continue;
                if(x[0][j]==y[0][k]&&x[1][j]==y[1][k]&&x[0][k]==y[0][j]&&x[1][k]==y[1][j])
                {
                    flag=true;
                    visx[j]=visy[k]=visx[k]=visy[j]=true;
                    break;
                }
            }
            if(!flag) 
            {
                f=false;
                break;
            }
        }
        for(int j=0;j<26;j++) if((x[0][j]!=0||x[1][j]!=0)&&!visx[j]) {f=false; break;}
        for(int j=0;j<26;j++) if((y[0][j]!=0||y[1][j]!=0)&&!visy[j]) {f=false; break;}
        if(f) ans.push_back(i);
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x+1);
    puts("");
    return 0;
}