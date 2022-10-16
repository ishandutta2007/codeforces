#include<iostream>
using namespace std;
string s;
int a,b;

int main(){
cin>>s;
for(auto i:s)if(i=='4')a++; else if(i=='7')b++;
if(!a &&!b)cout<<-1;
else if(a>=b)cout<<4;
else cout<<7;
return 0;
}