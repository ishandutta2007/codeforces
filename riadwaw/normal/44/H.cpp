#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
typedef long long int li;
char c[70];
li ar[70][10];
int n;
li rec(int ost,char ldig){
    if(ar[ost][ldig]==-1){      
        if(!ost){
            ar[ost][ldig]=1;
        }
        else{
            if((c[n-ost]+ldig)%2){
                ar[ost][ldig]=rec(ost-1,(c[n-ost]+ldig)/2)+rec(ost-1,(c[n-ost]+ldig)/2+1);
            }
            else{
                ar[ost][ldig]=rec(ost-1,(c[n-ost]+ldig)/2);
            }
        }
    }
    return ar[ost][ldig];
}
int main(){
    cin>>c;
    n=strlen(c);
    li cnt=0;
    for(int i=0;i<n;i++){
        c[i]-='0';
        for(int j=0;j<10;j++)
            ar[i][j]=-1;
    }
    for(int i=0;i<10;i++){
        cnt+=rec(n-1,i);
    }
    
    bool f=true;
    for(int i=1;i<n;i++){
        if(abs(c[i-1]-c[i])<=1){
        }
        else{
            f=false;
            break;
        }
    }
    if(f)
        cnt-=1;
    cout<<cnt;
    return 0;
}