#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{string a1,b1,c1,d1; int a,b,c,d,l=0,k=0,m=0,u=0,s=0; 
cin>>a1>>b1>>c1>>d1; a=a1.length()-2; b=b1.length()-2; c=c1.length()-2;d=d1.length()-2;
if ((2*a<=b && 2*a<=c && 2*a<=d )|| (a>=b*2 && a>=c*2 && a>=d*2 )) {l++; k++;} 
if ((2*b<=a && 2*b<=c && 2*b<=d )|| (b>=a*2 && b>=c*2 && b>=d*2 )) {l++; m++;} 
if ((2*d<=b && 2*d<=c && 2*d<=a )|| (d>=b*2 && d>=c*2 && d>=a*2 )) {l++; u++;} 
if ((2*c<=b && 2*c<=d && 2*c<=a )|| (c>=b*2 && c>=d*2 && c>=a*2 )) {l++; s++;}
if (l>1) cout<<"C"<<endl;
else if (k==1) cout<<"A"; 
else if (m==1) cout<<"B";
else if (u==1) cout<<"D";
else if (s==1) cout<<"C"<<endl; else cout<<"C"<<endl;
return 0;

}