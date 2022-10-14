#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int f=0,d=0,s=0;
    for(int i=1;i<=6;i++){
        if(abs(i-a)>abs(i-b)){
            s++;
        }
        else if(abs(i-a)<abs(i-b))
        {
            f++;
        }
        else{
            d++;
        }
    }
    cout<<f<<" "<<d<<" "<<s;
}