

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


int main(){
    int k[3];
    for(int i=0;i<=2;i++)scanf("%d",&k[i]);
    sort(k,k+3);
    bool flag=false;
    if(k[0]==1)flag=true;
    if(k[0]==2){
        if(k[1]==2)flag=true;
        else if(k[1]==4&&k[2]==4)flag=true;
    }
    if(k[0]==3){
        if(k[1]==3&&k[2]==3)flag=true;
    }
    if(flag==true)printf("YES");
    else printf("NO");
    
    return 0;
}