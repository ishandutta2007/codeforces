#include <iostream>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    for(int i=0;i*a<=c;i++){
        if((c-i*a)%b==0) return !printf("Yes\n");
    } 
    printf("No\n");
}