#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, m, clb[1010][1010], cla[1010], all, bea;
void add(int s, int c, int t){
    if(t*cla[s]<0)all++;
    if(t*clb[s][c]<0)bea++;
    cla[s]+=t;
    clb[s][c]+=t;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n+m;i++){
        int s, c;
        scanf("%d%d", &c,&s);
        if(i<n)add(s, c, 1);
        else add(s, c, -1);
    }
    printf("%d %d\n", all, bea);
    //scanf(" ");
    return 0;
}