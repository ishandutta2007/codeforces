#include<bits/stdc++.h>
using namespace std;
int main(){
    int r1,r2,c1,c2,d1,d2;
    int a,b,c,d;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    if((r1+r2)==(c1+c2) && (c1+c2)==(d1+d2) && (r1+c1-d2)%2==0){
       a=(r1+c1-d2)/2;
       b=r1-a;
       c=c1-a;
       d=d1-a;
       int arr[4]={a,b,c,d};
       sort(arr,arr+4);
       if(arr[0]>0 && arr[0]!=arr[3] && arr[1]!=arr[2] && arr[1]!=arr[0] && arr[2]!=arr[3] && arr[3]<10){
           cout<<a<<" "<<b<<'\n'<<c<<" "<<d<<endl;
           return 0;
       }
       cout<<-1<<endl;
       return 0;
    }
    cout<<-1<<endl;

}