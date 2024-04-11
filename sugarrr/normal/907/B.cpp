
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
    int m[10][10];
    for(int i=0;i<=8;i++)for(int j=0;j<=2;j++){
        char s[4];scanf("%s",s);
        for(int k=0;k<=2;k++){
            if(s[k]=='.')m[i][3*j+k]=0;
            else if(s[k]=='x')m[i][3*j+k]=1;
            else if(s[k]=='o')m[i][3*j+k]=2;
        }
    }
    int x,y;scanf("%d %d",&x,&y);
    int xx,yy;
    xx=(x+2)%3;yy=(y+2)%3;
    int flag=-1;
    for(int i=0;i<=2;i++)for(int j=0;j<=2;j++){
        if(m[xx*3+i][yy*3+j]==0)flag=1;
    }
    if(flag==1){
        for(int i=0;i<=2;i++)for(int j=0;j<=2;j++){
            if(m[xx*3+i][yy*3+j]==0)m[xx*3+i][yy*3+j]=3;
        }
    }else{
        for(int i=0;i<=8;i++)for(int j=0;j<=8;j++)if(m[i][j]==0)m[i][j]=3;
    }
    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
        if((j==0)&&(i==3||i==6)){
            printf("\n");
        }else if(j==3||j==6)printf(" ");
        
                if(m[i][j]==0)printf(".");
                else if (m[i][j]==1)printf("x");
                else if (m[i][j]==2)printf("o");
                else if (m[i][j]==3)printf("!");
        }
        printf("\n");
    }
    
    /*for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++)printf("%d",m[i][j]);
        printf("\n");
    }*/
    
    return 0;
}