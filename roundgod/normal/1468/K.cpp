#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int _,n,ax,ay,x[maxn],y[maxn];
char s[maxn];
bool check(int bx,int by){
    int x=0,y=0;
    for (int i=0;i<n;i++){
        int nx=x,ny=y;
        if (s[i]=='L') x--;
        else if (s[i]=='R') x++;
        else if (s[i]=='U') y++;
        else if (s[i]=='D') y--;
        if (x==bx&&y==by) x=nx,y=ny;
    }
    return !x&&!y;
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%s",s);
        n=strlen(s);
        for (int i=0;i<n;i++){
            x[i+1]=x[i];
            y[i+1]=y[i];
            if (s[i]=='L') x[i+1]--; 
            else if (s[i]=='R') x[i+1]++;
            else if (s[i]=='U') y[i+1]++;
            else if (s[i]=='D') y[i+1]--;
        }
        if (!x[n]&&!y[n]){
            printf("10000 10000\n");
            continue;
        }
        ax=0; ay=0;
        for (int i=1;i<=n;i++){
            if (!x[i]&&!y[i]) continue;
            if (check(x[i],y[i])) {ax=x[i];ay=y[i];break;}
        }
        printf("%d %d\n",ax,ay);
    }
    return 0;
}