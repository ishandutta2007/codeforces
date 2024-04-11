/*
ID: Sfiction
OJ: CF
PROB: 198B
*/
#include <cstdio>
#include <cstring>

const int MAXN=100000+10;

int n,k;
char wall[2][MAXN];
int time[2][MAXN];
int que[MAXN<<1];

bool BFS(){
    time[0][0]=1;
    que[0]=0;
    for (int l=0,r=1;l<r;++l){
        int side=que[l]/n,loc=que[l]%n;
        if (loc+k>=n)
            return true;
        if (!time[side][loc+1] && wall[side][loc+1]=='-'){
            time[side][loc+1]=time[side][loc]+1;
            que[r++]=side*n+loc+1;
        }
        if (loc && !time[side][loc-1] && wall[side][loc-1]=='-'
                && time[side][loc]<loc){
            time[side][loc-1]=time[side][loc]+1;
            que[r++]=side*n+loc-1;
        }
        if (!time[side^1][loc+k] && wall[side^1][loc+k]=='-'){
            time[side^1][loc+k]=time[side][loc]+1;
            que[r++]=(side^1)*n+loc+k;
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&k);
    scanf("%s%s",wall[0],wall[1]);
    printf(BFS() ? "YES" : "NO");
    return 0;
}