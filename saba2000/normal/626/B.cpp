#include<iostream>
#include<string>
using namespace std;
int n,r,g,b;
string s;
main()
{cin>>n>>s;
for (int i=0; i<n; i++){
if (s[i]=='R') r++; else

if (s[i]=='G') g++; 
else b++;}
if (b>0 && g>0 && r>0) {cout<<"BGR"<<endl; return 0;}
if ((b==0 && r*g!=0) || (b>=1 && r+g>1) || r+g==0) cout<<"B";
if ((g==0 && r*b!=0) || (g>=1 && r+b>1) || r+b==0) cout<<"G";
if ((r==0 && b*g!=0) || (r>=1 && b+g>1) || b+g==0) cout<<"R";


}