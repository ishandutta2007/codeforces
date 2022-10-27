#include <iostream>
#include <set>
using namespace std;
const int N = 2000+10;
int n,m,t;
int p[N],cp[N];
bool vis[N];

int bu=0,ans=0;
void cpu(){
    scanf("%d",&bu); vis[bu]=1;
}
void draw(int x){
    ans+=p[x]; vis[x]=1;
    printf("%d\n", x); fflush(stdout);
}
void me(){
    if(cp[bu] && vis[cp[bu]] == 0){
        draw(cp[bu]);
    } else {

        bool findcp=0;
        for(int i=1;i<=2*n;i++){
            if(vis[i]==0 && cp[i]) {
                findcp=1;
                if(p[i]>p[cp[i]]){
                    draw(i);
                } else {
                    draw(cp[i]);
                }
                break;
            }
        }

        if(!findcp) {
            int mx=0,bst=0;
            for(int i=1;i<=2*n;i++){
                if(vis[i]==0 && p[i]>=mx){
                    mx=p[i]; bst=i;
                }
            }
            draw(bst);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=2*n;i++)scanf("%d",&p[i]);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        cp[x]=y,cp[y]=x;
    }

    scanf("%d",&t);
    for(int i=1;i<=n;i++){
        if(t==1){
            me(); cpu(); 
        } else {
            cpu(); me();
        }
    }
}