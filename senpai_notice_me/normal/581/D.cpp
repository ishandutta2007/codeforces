#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_A 200

int x[3],y[3],Sum=0,a;
int ad[MAX_A][MAX_A];

bool check(int x) {
    int t=sqrt(x);
    return (t*t==x);
}

int main() {
    for (int i=0;i<3;i++) {
        scanf("%d%d",x+i,y+i);
        if (x[i]>y[i]) swap(x[i],y[i]);
        Sum+=x[i]*y[i];
    }
    if (!check(Sum)) {
        puts("-1"); return 0;
    }
    a=sqrt(Sum);
    for (int i=0;i<3;i++)
        if (x[i]>a || y[i]>a) {
            puts("-1"); return 0;
        }
    for (int q=0;q<3;q++)
    for (int w=0;w<3;w++)
    for (int e=0;e<3;e++) {
        if (q==w || w==e || e==q) continue;
        for (int i=0;i<3;i++) if (x[i]>y[i]) swap(x[i],y[i]);
        if (y[q]==a && y[w]==a && y[e]==a && x[q]+x[w]+x[e]==a) {
            printf("%d\n",a);
            for (int i=1;i<=x[q];i++) {
                for (int j=1;j<=a;j++) printf("%c",'A'+q);
                printf("\n");
            }
            for (int i=1;i<=x[w];i++) {
                for (int j=1;j<=a;j++) printf("%c",'A'+w);
                printf("\n");
            }
            for (int i=1;i<=x[e];i++) {
                for (int j=1;j<=a;j++) printf("%c",'A'+e);
                printf("\n");
            }
            return 0;
        }
        //**********************************************************************
        if (y[q]==a) {
            if (x[q]+x[w]==a) swap(y[w],x[w]);
            if (x[q]+x[e]==a) swap(y[e],x[e]);
            if (y[w]+x[q]==a && y[e]+x[q]==a && x[w]+x[e]==a) {
                printf("%d\n",a);
                for (int i=1;i<=x[q];i++) {
                    for (int j=1;j<=a;j++) printf("%c",'A'+q);
                    printf("\n");
                }
                for (int i=1;i<=(a-x[q]);i++) {
                    for (int j=1;j<=x[w];j++) printf("%c",'A'+w);
                    for (int j=1;j<=x[e];j++) printf("%c",'A'+e);
                    printf("\n");
                }
                return 0;
            }
        }
        //**********************************************************************
    }
    puts("-1");
    return 0;
}