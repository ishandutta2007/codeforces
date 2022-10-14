#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    char arr[r][c];
    int row=0,column=0;
    int visitr[r]={0},visitc[c]={0};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
           cin>>arr[i][j];
            if(arr[i][j]=='S'){
                if(!(visitr[i]))
                {row++;
                visitr[i]=1;
                }
                if(!(visitc[j])){
               column++;
               visitc[j]=1;
                }
                
            }
        }
    }
int t1=c*(r-row);
int t2=r*(c-column);
int k=t1+t2-(r-row)*(c-column);
if(k>=0)
cout<<k;
else
{
    cout<<0;
}

 
}