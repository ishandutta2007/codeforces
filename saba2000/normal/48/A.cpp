#include <iostream>
#include <string>
using namespace std;
int q(string s)
{if (s[0]=='r') return 1; else if (s[0]=='p') return 2; else return 3;}
int f(int a, int b)
{if (a==1 && b==3) return 1; else 
if (b==1 && a==3) return 0; else
if (a>b) return 1; else
if (b>a) return 0; else
return 0;
}
int main ()
{string a1,b1,c1;
int a,b,c;
cin>>a1>>b1>>c1;
a=q(a1); b=q(b1); c=q(c1);
if (f(a,b)==1 && f(a,c)==1) cout<<"F"<<endl; else
if (f(b,a)==1 && f(b,c)==1) cout<<"M"<<endl; else
if (f(c,a)==1 && f(c,b)==1) cout<<"S"<<endl; else
                            cout<<"?"<<endl;
return 0;
}