
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main() {
    int n;
    scanf("%d",&n);
    int north=0;
    int i;
    int flag=1; /* 10*/
    for(i=1;i<=n;i++){
        int x;
        char dir[10];
        scanf("%d %s",&x,dir);
        
        if(north==0){
            if(dir[0]!='S' || x>20000){
                flag=0;
                break;
            }else{
                north+=x;
            }
        }else if(north==20000 ){
            if(dir[0]!='N' ||x>20000){
                flag=0;
                break;
            }else{
                north-=x;
            }
        }else{
            if(dir[0]=='S'){
                if(x+north>20000){
                    flag=0;
                    break;
                }else{
                    north=north+x;
                }
            }else if(dir[0]=='N'){
                if(north-x<0){
                    flag=0;
                    break;
                }else{
                    north=north-x;
                }
            }
        }
    }
    if(north!=0)flag=0;
    if(flag==1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
    return 0;
}