#include <iostream>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if(min(b,c)>=a) printf("Yes\n"); else printf("No\n");
}