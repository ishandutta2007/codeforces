#include<iostream>
using namespace std;
string s;
int n,a,b;

int main(){
cin>>n>>s;
for(auto i:s)if(i=='x')a++; else b++;
cout<<abs(a-b)/2<<endl;
for(auto i:s){
if(i=='x'&&a>b)cout<<'X', a--,b++;
else if(i=='X'&&b>a)cout<<'x', a++,b--;
else cout<<i;
}
return 0;
}