/*
ID: Sfiction
OJ: CF
PROB: 442A
*/
#include <cstdio>
#include <cstring>

char color[128];
int cnt1[32];

int card[6][6];
int id[6][6];

void Pre(){
    int i;
    color['R']=1;
    color['G']=2;
    color['B']=3;
    color['Y']=4;
    color['W']=5;
    for (i=1;i<32;++i)
        cnt1[i]=cnt1[i>>1]+(i&1);
}
void Init(){
    int n;
    char chr[10];
    memset(card,0,sizeof(card));
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%s",chr);
        card[color[chr[0]]][chr[1]-48]=1;
    }
}
void Out(){
    int i,j;
    for (i=1;i<=5;++i){
        for (j=1;j<=5;++j)
            printf("%d ",card[i][j]);
        printf("\n");
    }
}
int Check(){
    int i,j,k,l;
    for (i=1;i<=5;++i)
        for (j=1;j<=5;++j)
            for (k=1;k<=5;++k)
                for (l=1;l<=5;++l)
                    if (card[i][j]&&card[k][l])
                        if (i!=k||j!=l)
                            if (id[i][j]==id[k][l])
                                return 0;
    return 1;
}
int Attempt(){
    int icol,inum;
    int i,j;
    int temp,ans;
    ans=10;
    for (icol=0;icol<32;++icol)
        for (inum=0;inum<32;++inum){
            memset(id,0,sizeof(id));
            for (i=0;i<5;++i)
                if ((icol&(1<<i))!=0)
                    for (j=1;j<=5;++j)
                        id[i+1][j]+=(i+1)*10;
            for (i=0;i<5;++i)
                if ((inum&(1<<i))!=0)
                    for (j=1;j<=5;++j)
                        id[j][i+1]+=i+1;
            if (Check()){
                temp=cnt1[icol]+cnt1[inum];
                if (temp<ans)
                    ans=temp;
            }
        }
    return ans;
}
int main(){
    Pre();
    Init();
    printf("%d",Attempt());
    //Out();
    return 0;
}