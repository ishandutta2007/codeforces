#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define LL __int64
#define ll __int64
#define mem(x , y) memset(x , y , sizeof(x))
#define lowbit(x) (x&(-x))
const ll mod = 1e9+7;
const int maxn = 1e5+10 ;
struct node{
    int l , d ;
    int val ;
    node(){
        l = -1 , d = -1 ;
    }
}d[1100*1100];
int addr(int i , int j){
    return i * 1100 + j ;
}
node * right(node * tmp){
    return d + tmp -> l ;
}
node * down(node * tmp){
    return d + tmp -> d ;
}
void print(node * tmp){
    printf("thing : %d %d\n", (tmp - d) / 1100 , (tmp-d) % 1100) ;
}
void change(node * t1 , node * t2, int h ,int w){
    node * tl1 = t1 ; node * tl2 = t2 ;
    for(int i=0;i<w;i++){
        tl1 = d + tl1->l ; tl2 = d + tl2->l ;
        swap(tl1->d , tl2->d) ;
    }
    tl1 = down(tl1) ; tl2 = down(tl2) ;
    for(int i=0;i<h;i++){
        swap(tl1->l , tl2->l) ;
        tl1 = down(tl1) ; tl2 = down(tl2) ;
    }
    tl1 = t1 ; tl2 = t2 ;
    for(int i=0;i<h;i++){
        tl1 = down(tl1) ; tl2 = down(tl2) ;
        swap(tl1->l , tl2 -> l) ;
    }
    tl1 = right(tl1) ; tl2 = right(tl2) ;
    for(int i=0;i<w;i++){
        swap(tl1->d , tl2 -> d) ;
        tl1 = right(tl1) ; tl2 = right(tl2) ;
    }
}
int main(){
    int n , m , q; scanf("%d%d%d" , &n,&m,&q) ;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) {
            d[addr(i , j)].l = addr(i , j+1) ;
            d[addr(i , j)].d = addr(i+1, j)  ;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            scanf("%d" , &(d[addr(i , j)].val)) ;
        }
    }
    for(int t = 0 ; t < q ; t ++){
        int ta,tb,tc,td,th,tw ;
        scanf("%d%d%d%d%d%d" , &ta,&tb,&tc,&td,&th,&tw) ;
        node * tmp1 = &d[addr(ta-1 , 0)] ;
        node * tmp2 = &d[addr(tc-1 , 0)] ;
        for(int i=0;i<tb-1;i++){
            tmp1 = d+tmp1->l ;
        }
        for(int i=0;i<td-1;i++){
            tmp2 = d+tmp2->l ;
        }
        change(tmp1 , tmp2 , th , tw) ;
    }
    for(int i=1;i<=n;i++){
        node * tmp = d + addr(i , 0) ;
        for(int j=0;j<m;j++){
            tmp = right(tmp) ;
            printf("%d" , tmp->val) ;
            if(j == m-1) printf("\n") ;
            else printf(" ") ;
        }
    }
}