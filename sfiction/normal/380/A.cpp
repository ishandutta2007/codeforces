/*
ID: Sfiction
OJ: CF
PROB: 380A
*/
#include <cstdio>

const int MAXM=100000+5,MAXN=100000+5,MAXL=100000+5;

int m;

int com[MAXM][2];
long long len[MAXM];

int seq[MAXL],lens;

void Pre(){
    int i,k;
    int b;
    scanf("%d",&m);
    len[0]=0;
    lens=1;
    for (i=1;i<=m;++i){
        scanf("%d%d",&com[i][0],&com[i][1]);
        if (com[i][0]==1){
            len[i]=len[i-1]+1;
            if (lens<MAXL){
                seq[lens]=com[i][1];
                ++lens;
            }
        }
        else{
            scanf("%d",&b);
            len[i]=len[i-1]+com[i][1]*b;
            for (;lens<MAXL && b;--b)
                for (k=1;lens<MAXL && k<=com[i][1];++k,++lens)
                    seq[lens]=seq[k];
        }
    }
}

int BinarySearch(long long key){
    int low=0,high=m+1;
    int mid;
    while (high-low>1){
        mid=(high+low)>>1;
        if (len[mid]<=key)
            low=mid;
        else
            high=mid;
    }
    return low;
}

void Work(){
    int n;
    int loc;
    long long key;
    scanf("%d",&n);
    for (;n;--n){
        scanf("%I64d",&key);
        loc=BinarySearch(key);
        if (com[loc][0]==1 && len[loc]==key)
            printf("%d",com[loc][1]);
        else{
            if (len[loc]==key)
                --loc;
            key-=len[loc];
            --key;
            key%=com[loc+1][1];
            ++key;
            printf("%d",seq[key]);
        }
        if (n>1)
            printf(" ");
    }
}

int main(){
    Pre();
    Work();
    return 0;
}