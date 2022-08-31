#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
#define x0 fxxk
#define y0 fxck
#define x1 fuxk
#define y1 fucx
using namespace std;
using ll=long long;
using ld=long double;
using pr=pair<int,int>;
constexpr int N=2e5+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
char s[N],t[3][N],typ[5],tc[5];
int la[26][N],dp[255][255][255],top[3],n,num,q;
int main(){
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=0;i<26;++i)la[i][n+1]=la[i][n+2]=n+1;
    for(int ps=n;~ps;--ps){
        for(int i=0;i<26;++i)la[i][ps]=la[i][ps+1];
        if(ps>0)la[s[ps]-'a'][ps]=ps;
    }
    rep(i,q){
        scanf("%s%d",typ+1,&num);--num;
        if(typ[1]=='+'){
            scanf("%s",tc+1);
            ++top[num];t[num][top[num]]=tc[1];
            for(int i=num==0?top[0]:0;i<=top[0];++i)
                for(int j=num==1?top[1]:0;j<=top[1];++j)
                    for(int k=num==2?top[2]:0;k<=top[2];++k){
                        dp[i][j][k]=n+1;
                        if(i>0)dp[i][j][k]=min(dp[i][j][k],la[t[0][i]-'a'][dp[i-1][j][k]+1]);
                        if(j>0)dp[i][j][k]=min(dp[i][j][k],la[t[1][j]-'a'][dp[i][j-1][k]+1]);
                        if(k>0)dp[i][j][k]=min(dp[i][j][k],la[t[2][k]-'a'][dp[i][j][k-1]+1]);
                    }

        }else{
            --top[num];
        }
        puts(dp[top[0]][top[1]][top[2]]==n+1?"NO":"YES");
    }
    return 0;
}