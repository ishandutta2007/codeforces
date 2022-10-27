#include<iostream>
#include<stdio.h>
using namespace std;
int a[100+2],num1=0;
int b[100+2],num2=0;
bool pos[102];
int index=0;
int main(){
    char c;
    while(scanf("%c",&c),c!='='){
        if(c=='+'){
            num1++;
            pos[++index]=true;
        }
        if(c=='-'){
            num2++;
            pos[++index]=false;
        }
    }
    num1++;
    scanf("%c",&c);
    int n;scanf("%d",&n);
    if(num1*n-num2<n) printf("Impossible\n");
    else if(num1-num2*n>n) printf("Impossible\n");
    else{
        printf("Possible\n");
        int sum1,sum2;
        sum1=max(num2+n,num1);//a
        sum2=sum1-n;//b
        if(n>sum1-num1+1){
            printf("%d ",sum1-num1+1);
            sum1=(num1-1);
            num1--;
        }
        else{
            printf("%d ",n);
            sum1-=n;
            num1--;
        }
        for(int i=1;i<=index;i++){
            if(pos[i]){
                printf("+ ");
                if(n>sum1-num1+1){
                    printf("%d ",sum1-num1+1);
                    sum1=(num1-1);
                    num1--;
                }
                else{
                    printf("%d ",n);
                    sum1-=n;
                    num1--;
                }
            }else{
                printf("- ");
                if(n>sum2-num2+1){
                    printf("%d ",sum2-num2+1);
                    sum2=(num2-1);
                    num2--;
                }
                else{
                    printf("%d ",n);
                    sum2-=n;
                    num2--;
                }
            }
        }
        printf("= %d\n",n);
    }
    return 0;
}