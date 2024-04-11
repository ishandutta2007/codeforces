/*
ID: Sfiction
OJ: CF
PROB: 493A
*/
#include <cstdio>
#include <cstring>

const int MAXN=100+10;

char team[2][30];
int player[2][MAXN];

int main(){
    int n;
    int time,num;
    char s1[10],card[10];

    scanf("%s%s",&team[0][0],&team[1][0]);
    scanf("%d",&n);
    memset(player,0,sizeof(player));
    while (n--){
        scanf("%d%s%d%s",&time,s1,&num,&card);
        s1[0]=s1[0]=='a';
        card[0]=(card[0]=='r')+1;
        if (player[s1[0]][num]>=2)
            continue;
        player[s1[0]][num]+=card[0];
        if (player[s1[0]][num]>=2)
            printf("%s %d %d\n",team[s1[0]],num,time);
    }
    return 0;
}