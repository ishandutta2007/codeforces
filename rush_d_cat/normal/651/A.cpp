#include<iostream>
using namespace std;
int main(){
    int a,b,cnt=0;cin>>a>>b;
    while(a>0&&b>0&&!(a==1&&b==1)){
        if(a>=b){a-=2;b+=1;}
        else{a+=1;b-=2;}
        cnt++;
    }
    cout<<cnt<<endl;
}