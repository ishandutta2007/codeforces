#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2||y1==y2){
        if(x1==x2){
            int s=abs(y1-y2);
            x3=x1+s;
            x4=x3;
            y3=y1;
            y4=y2;
        }
        else{
            int s=abs(x1-x2);
            y3 = y1+s;
            y4=y3;
            x3=x1;
            x2 =x4;
        }
    }
    else{
        if(abs(x1-x2)==abs(y1-y2)){
            x3=x1;
            y3=y2;
            x4=x2;
            y4=y1;
        }
       else{
           cout<<-1;
           return 0;
       } 
    }
    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}