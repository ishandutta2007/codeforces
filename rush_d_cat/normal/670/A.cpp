#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    int x=(n/7)*2,y=(n/7)*2;
    if(n%7>=6) x+=n%7-5;
    y+=min(2,n%7);
    cout<<x<<" "<<y<<endl;
}