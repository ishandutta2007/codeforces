#include <iostream>
using namespace std;
long long x,a,i,k;
int main(){
cin>>x;a=1,i=1;while(x>=i){if(i&1)a=(a-1)*3;else a=(a+1)*3;i++;a%=1000000007;}cout<<a<<endl;}