#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=1005; 

bool e[MAXN][MAXN];

int n;

inline void clear(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            e[i][j]=0;
}

typedef pair<int,int>op;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

vector<op>s;

int type;

inline void Xor(int x,int y){
    for(int i=2;i<=n;++i)
        if(e[i][x]&&e[i][y]){
            e[x][y]=e[y][x]=0;
            e[1][i]=e[i][1]=1;
            if(!type)s.pb(mp(x,y));
            else s.pb(mp(1,i));
            break;
        }
}

inline void Solve(){
    clear();
    for(int i=3,x,y;i<n;++i){
        scanf("%d%d",&x,&y);
        e[x][y]=e[y][x]=1;
    }
    for(int i=1;i<=n;++i){
        int j=i+1;
        if(i==n)j=1;
        e[i][j]=e[j][i]=1;
    }
    s.clear();
    for(int i=2;i<=n;){
        if(e[1][i]){
            ++i;
            continue;
        }
        for(int j=i+1;j<=n;++j)
            if(e[1][j]){
                Xor(i-1,j);
                break;
            }
    }
}

op ans[MAXN*20];

int cnt;

int main(){
    scanf("%d",&n);
    Solve();
    for(int i=0;i<s.size();++i)
        ans[++cnt]=s[i];
    type=1;  
    Solve();
    for(int i=s.size();i;--i)
        ans[++cnt]=s[i-1];
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;++i)
        printf("%d %d\n",ans[i].fi,ans[i].se); 
    return 0;
}