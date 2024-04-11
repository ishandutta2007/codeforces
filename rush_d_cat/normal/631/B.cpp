#include<iostream>
using namespace std;
typedef __int64 ll;
const int MAX=5000+2;
struct Row{
    ll order;
    ll pos;
    ll color;
}row[MAX];
struct Col{
    ll order;
    ll pos;
    ll color;
}col[MAX];
int main(){
    int m,n;cin>>n>>m;
    ll k;scanf("%I64d",&k);
    for(int i=1;i<=k;i++){
        int a;scanf("%d",&a);
        ll tmp1,tmp2;scanf("%I64d%I64d",&tmp1,&tmp2);
        if(a==1){
            row[tmp1].order=k-i;
            row[tmp1].pos=tmp1;
            row[tmp1].color=tmp2;
        }else{
            col[tmp1].order=k-i;
            col[tmp1].pos=tmp1;
            col[tmp1].color=tmp2;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(row[i].color==0||col[j].color==0) printf("%I64d",max(row[i].color,col[j].color));
            else{
                if(row[i].order<col[j].order) printf("%I64d",row[i].color);
                else printf("%I64d",col[j].color);
            }
            if(j==m) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}