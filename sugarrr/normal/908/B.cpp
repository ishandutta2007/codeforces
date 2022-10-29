

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
typedef long long ll;
using namespace std;

char s[55][55];
int si,sj,ei,ej;
char A[105];
int a[105];
int len;
int n,m;

bool robot(int r,int u,int l,int d){
    int i=si,j=sj;
    bool flag=true;
    int k=0;
    while((i!=ei||j!=ej)&&flag==true&&k<=len-1){
        if(a[k]==r){
            i++;
        }else if(a[k]==u){
            j++;
        }else if(a[k]==l){
            i--;
        }else if(a[k]==d){
            j--;
        }
        if(i<0||i>=n||j<0||j>=m)flag=false;
        if(s[i][j]=='#')flag=false;
        k++;
    }
    if(flag==false)return false;
    else if(i==ei&&j==ej)return true;
    else return false;/*true*/
}


int main(){
    cin>>n>>m;
   
    for(int i=0;i<=n-1;i++){
        scanf("%s",s[i]);
        for(int j=0;j<=m-1;j++){
            if(s[i][j]=='S'){
                si=i;
                sj=j;
            }else if(s[i][j]=='E'){
                ei=i;
                ej=j;
            }
        }
    }
    scanf("%s",A);
    len=strlen(A);
    for(int i=0;i<len;i++)a[i]=(int)A[i]-'0';
    
    int ans=0;
    
    if((robot(1,2,3,0))==true)ans++;
    if((robot(1,2,0,3))==true)ans++;
    if((robot(1,3,2,0))==true)ans++;
    if((robot(1,3,0,2))==true)ans++;
    if((robot(1,0,2,3))==true)ans++;
    if((robot(1,0,3,2))==true)ans++;
    if((robot(2,1,3,0))==true)ans++;
    if((robot(2,1,0,3))==true)ans++;
    if((robot(2,3,1,0))==true)ans++;
    if((robot(2,3,0,1))==true)ans++;
    if((robot(2,0,1,3))==true)ans++;
    if((robot(2,0,3,1))==true)ans++;
    if((robot(3,1,2,0))==true)ans++;
    if((robot(3,1,0,2))==true)ans++;
    if((robot(3,2,1,0))==true)ans++;
    if((robot(3,2,0,1))==true)ans++;
    if((robot(3,0,1,2))==true)ans++;
    if((robot(3,0,2,1))==true)ans++;
    if((robot(0,1,2,3))==true)ans++;
    if((robot(0,1,3,2))==true)ans++;
    if((robot(0,2,1,3))==true)ans++;
    if((robot(0,2,3,1))==true)ans++;
    if((robot(0,3,1,2))==true)ans++;
    if((robot(0,3,2,1))==true)ans++;
    printf("%d",ans);
    
    return 0;
}