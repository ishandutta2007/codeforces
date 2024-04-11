
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


int main() {
    int a,b,c,d;scanf("%d %d %d %d",&a,&b,&c,&d);
    int x=-100,y,z;
    for(int i=1;i<=200;i++){
        for(int  j=1;j<=200;j++){
            for(int k=1;k<=200;k++){
                if(i>j&&j>k&&a<=i&&i<=2*a&&b<=j&&j<=2*b&&c<=k&&k<=2*c&&d<=k&&k<=2*d&&!(d<=j&&j<=2*d)){
                    x=i;
                    y=j;
                    z=k;
                    break;
                }
            }
        }
    }
    if(x==-100)printf("-1\n");
    else printf("%d\n%d\n%d\n",x,y,z);
    return 0;
}