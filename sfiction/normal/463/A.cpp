/*
ID: Sfiction
OJ: CF
PROB: 463A
*/
#include <cstdio>

int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    s*=100;

    int max=-1;
    for (int i=0;i<n;++i){
        int d,c;
        scanf("%d%d",&d,&c);
        if (s>=d*100+c && max<(100-c)%100)
            max=(100-c)%100;
    }
    printf("%d",max);
    return 0;
}