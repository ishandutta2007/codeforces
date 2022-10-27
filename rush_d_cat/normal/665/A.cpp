#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a1,a2;cin>>a1>>a2;
    int b1,b2;cin>>b1>>b2;
    char a,b,c,d,e;cin>>a>>b>>c>>d>>e;
    int x=0,y=0;
    int time=60*(10*(a-'0')+b-'0')+10*(d-'0')+e-'0'-300;
    int s=max((time-b2),0);
    int t=min((time+a2),24*60-1-300);
    if(time-b2<0){
        s=0;
    }else{
        s=time-b2;
        x=1;
    }
    if(time+a2>24*60-1-300){
        t=24*60-1-300;
    }else{
        t=time+a2;
        y=1;
    }
    int cnt=0;
    //cout<<s<<" "<<t<<endl;
    for(int i=s+x;i<=t-y;i++){
        if(i%b1==0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}