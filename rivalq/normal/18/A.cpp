#include<bits/stdc++.h>
using namespace std;
int ch(int x1,int y1,int x2,int y2,int x3 ,int y3){
    int d1=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    int d2=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    int d3 =(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
    int ma=max(d1,max(d2,d3));
    if(d1==0 || d2==0 || d3==0) return 0;
    if(2*ma==(d1+d2+d3)){
        return 1;
    }
    return 0;


}
int main(){
    int x1,y1,x2,y2,x3,y3;
     cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int arr[6]={x1,y1,x2,y2,x3,y3};
   
    if(ch(x1,y1,x2,y2,x3,y3)){
        cout<<"RIGHT\n";
        return 0;
    }
    for(int i=0;i<6;i++){
        arr[i]+=1;
        if(ch(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5])){
            cout<<"ALMOST\n";
            return 0;
        }
        arr[i]-=1;
    }
    for(int i=0;i<6;i++){
        arr[i]-=1;
        if(ch(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5])==1){
            cout<<"ALMOST\n";
            return 0;
        }
        arr[i]+=1;
    }
    cout<<"NEITHER\n";
}