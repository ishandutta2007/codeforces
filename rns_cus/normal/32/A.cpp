#include<stdio.h>
#include<algorithm>
using namespace std;

int n, d, h[1111],tot;
int main(){
    scanf("%d %d", &n, &d);
    for(int i=0; i<n; i++){
        scanf("%d",&h[i]);
    }
    sort(h,h+n);
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(h[j]-h[i]<=d)tot++;
    printf("%d\n",tot*2);
    ///return 7;
}