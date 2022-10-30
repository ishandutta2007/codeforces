///d
#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 111

struct area{
    int x1,x2,y1,y2;
} r[N], rr;

int ar[N], x1[N], x2[N], y1[N], y2[N], w, h, n, fg[N];

int main(){
 ///   freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &w, &h, &n);
    r[0].x1=r[0].y1=0;
    r[0].x2=w;r[0].y2=h;
    for(int i=0; i<n; i++)
        scanf("%d %d %d %d",&x1[i], &y1[i], &x2[i], &y2[i]);
    for(int step=0; step<n; step++){
        for(int i=0; i<n; i++)if(fg[i]==0){
            int j;
            for(j=0; j<=step; j++){
                rr=r[j];
                if(x1[i]==x2[i]){
                    if(rr.x1<x1[i] && x1[i]<rr.x2 && rr.y1==y1[i] && rr.y2==y2[i]){
                        r[step+1]=rr;
                        r[j].x2=r[step+1].x1=x1[i];
                        break;
                    }
                }
                else{
                    if(rr.y1<y1[i] && y1[i]<rr.y2 && rr.x1==x1[i] && rr.x2==x2[i]){
                        r[step+1]=rr;
                        r[j].y2=r[step+1].y1=y1[i];
                        break;
                    }
                }
            }
            if(j<=step){
   //             printf("%d\n",i);
                fg[i]=1;
                break;
            }
        }
    }
    for(int i=0; i<=n; i++) ar[i]=(r[i].x2-r[i].x1)*(r[i].y2-r[i].y1);
    sort(ar, ar+n+1);
    for(int i=0; i<=n; i++)printf("%d%c",ar[i],i==n?'\n':' ');

    return 0;
}