#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
const int h=21,b=360;
bool f[23][360],g[23][360],vis[23][360];
int _,n;
queue<pi> q;
char s[2];
void go(int x,int y){
    if (vis[x][y]) return;
    vis[x][y]=1;
    q.push((pi){x,y});
}
int main(){
    cin >> _;
    while (_--){
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        cin >> n;
        while (n--){
            int x,y,z; cin >> s >> x >> y >> z;
            if (s[0]=='C'){
                while (y!=z){
                    f[x][y]=1;
                    y=(y+1)%b;
                }
            } else {
                for (int i=x;i<y;i++) g[i][z]=1;
            }
        }
        for (int i=0;i<b;i++) q.push((pi){0,i}),vis[0][i]=1;
        bool ok=0;
        while (!q.empty()){
            pi tmp=q.front(); q.pop();
            int x=tmp.F,y=tmp.S;
            if (x==21) {ok=1;continue;}
            if (!g[x][y]) go(x,(y+b-1)%b);
            if (!g[x][(y+1)%b]) go(x,(y+1)%b);
            if (!f[x+1][y]) go(x+1,y);
            if (x>0&&!f[x][y]) go(x-1,y);
        }
        if (ok) puts("YES"); else puts("NO"); 
    }
    return 0;
}