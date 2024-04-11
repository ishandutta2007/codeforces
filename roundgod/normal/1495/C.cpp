#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
char s[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        for(int i=0;i<n;i+=3)
        {
            for(int j=0;j<m;j++) s[i][j]='X';
            if(i==n-1||i==n-2) continue;
            else if(i+3<n)
            {
                bool f=false;
                for(int j=0;j<m;j++) if(s[i+1][j]=='X') {s[i+2][j]='X'; f=true; break;}
                if(f) continue;
                for(int j=0;j<m;j++) if(s[i+2][j]=='X') {s[i+1][j]='X'; f=true; break;}
                if(f) continue;
                s[i+1][0]=s[i+2][0]='X';
            }
            else
            {
                for(int j=0;j<m;j++) if(s[i+2][j]=='X') s[i+1][j]='X';
            }
        }
        for(int i=0;i<n;i++) printf("%s\n",s[i]);
    }
    return 0;
}