#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef pair<int,int> pr;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool in[22][365];
int T,n,ps[22][365];
char s[5];
pr q[21*360+5];int l,r;
int main() {
    for(scanf("%d",&T);T--;){
        rep(i,21)rep(j,360){
            in[i][j]=0;
            ps[i][j]=2|8;
            if(i!=0)ps[i][j]|=4;
            if(i!=20)ps[i][j]|=1;
        }
        scanf("%d",&n);
        rep(tim,n){
            int x,y,z;
            scanf("%s%d%d%d",s,&x,&y,&z);
            if(s[0]=='C'){
                for(int i=y;i!=z;i=(i+1)%360){
                    ps[x-1][i]&=15-1;
                    ps[x][i]&=15-4;
                }
            }else{
                for(int i=x;i<y;++i){
                    ps[i][z]&=15-8;
                    ps[i][(z+359)%360]&=15-2;
                }
            }
        }
        l=0,r=1;q[0]=mp(0,0);in[0][0]=1;
        while(l<r){
            pr p=q[l++];
            rep(i,4)if((ps[p.st][p.nd]&(1<<i))){
                int tx=p.st+dx[i],ty=(p.nd+dy[i]+360)%360;
                if(!in[tx][ty]){
                    //printf("%d %d\n",tx,ty);
                    in[tx][ty]=1;
                    q[r++]=mp(tx,ty);
                }
            }
        }
        //printf("%d\n",r);
        puts(in[20][0]?"YES":"NO");
    }
    return 0;
}