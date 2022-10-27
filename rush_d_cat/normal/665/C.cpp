#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int main(){
    char a[200000+10];
    cin>>a;
    int l=strlen(a);
    for(int i=0;i<l-1;i++){
        int tmp=i;
        int tmp1=1;
        while(a[tmp]==a[tmp+tmp1]){
            tmp1++;
        }
        if(tmp1>1){
            if(tmp1%2==1){
                for(int j=tmp+1;j<=tmp+tmp1-1;j+=2){
                    if(a[j]=='a') a[j]=char(a[j]+1);
                    else a[j]=char(a[j]-1);
                }
            }else{
                for(int j=tmp;j<=tmp+tmp1-1;j+=2){
                    if(j==0){
                        if(a[j]=='a') a[j]=char(a[j]+1);
                        else a[j]=char(a[j]-1);
                        continue;
                    }
                    if(j==tmp){
                        if(a[j-1]=='a'||a[j-1]=='b'){
                            a[j]=(char)(a[j-1]+1);
                            if(a[j]==a[j+1]){
                                a[j]=char(a[j]+1);
                            }
                        }else{
                             a[j]=(char)(a[j-1]-1);
                            if(a[j]==a[j+1]){
                                a[j]=char(a[j]-1);
                            }
                        }
                        continue;
                    }
                    if(a[j]=='a') a[j]=char(a[j]+1);
                    else a[j]=char(a[j]-1);
                }
            }
        }
    }
    for(int i=0;i<l;i++){
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}