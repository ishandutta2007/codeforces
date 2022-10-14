#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,r,c,a,b,d1=-1,d2=-1,d3=-1,d4=-1;
    cin>>n>>m>>r>>c>>a>>b;
    if((r==1||r==n)&&(c==1||c==m)){cout<<0<<endl;return 0;}
    int arr[4]={-1,-1,-1,-1};
    int a1=-1,a2=-1,b1=-1,b2=-1;
    if((n-r)%a==0) a1=(n-r)/a;
    if((r-1)%a==0) a2=(r-1)/a;
    if((m-c)%b==0) b1=(m-c)/b;
    if((c-1)%b==0) b2=(c-1)/b;
    if(abs(a1-b1)%2==0 && a1!=-1 && b1!=-1) d1=max(a1,b1);
    if(abs(a1-b2)%2==0 && a1!=-1 && b2!=-1) d2=max(a1,b2);
    if(abs(a2-b1)%2==0 && a2!=-1 && b1!=-1) d3=max(a2,b1);
    if(abs(a2-b2)%2==0 && a2!=-1 && b2!=-1) d4=max(a2,b2);
    d1 = (d1>d2 && d2!=-1)?d2:(d1!=-1)?d1:d2;
    d3 = (d3>d4 && d4!=-1)?d4:(d3!=-1)?d3:d4;
    d1 = (d3>d1 && d1!=-1)?d1:(d3!=-1)?d3:d1;
    if(d1!=-1){
        if((1<=(r-a) || (r+a)<=n) && (1<=(c-b) || (c+b)<=m)) cout<<d1<<endl;
        else cout<<"Poor Inna and pony!"<<endl;
    }
    else {
        cout<<"Poor Inna and pony!"<<endl;
    }







   



    

}