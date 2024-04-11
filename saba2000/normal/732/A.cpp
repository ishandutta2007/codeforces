#include<iostream>
using namespace std;int a,b,i;main(){cin>>a>>b;X:i++;if(!(i*a%10)|| i*a%10==b){cout<<i;return 0;}goto X;}