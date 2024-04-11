#include <iostream>
#include <string>
using namespace std;

int a=3,b=2,c=1; 
void f(string a1)
{if (a1=="A<B" && a>b || a1=="B>A" && a>b) swap (a,b);
if (a1=="A>B" && a<b || a1=="B<A" && a<b) swap (a,b);
if (a1=="A<C" && a>c || a1=="C>A" && a>c) swap (a,c);
if (a1=="A>C" && a<c || a1=="C<A" && a<c) swap (a,c);
if (a1=="C<B" && c>b || a1=="B>C" && b<c) swap (c,b);
if (a1=="C>B" && c<b || a1=="B<C" && b>c) swap (c,b);
}
int g(string c1)
{if (c1=="A>B" && a<b || c1=="B<A" && a<b || c1=="B>A" && a>b || c1=="A<B" && a>b || c1=="A>C" && a<c || c1=="C<A" && a<c || c1=="A<C" && a>c || c1=="C>A" && a>c || c1=="C>B" && c<b || c1=="B<C" && c<b || c1=="B>C" && b<c || c1=="C<B" && c>b )
return 1; else return 0;
}

int main ()
{string a1,b1,c1; cin>>a1>>b1>>c1;
f(a1); 
f(b1);
f(c1);
f(a1);
f(b1);
f(c1);
f(a1);
f(b1);
f(c1);
if (g(a1)+g(b1)+g(c1)!=0) cout<<"Impossible"<<endl; else{
if (a==1) cout<<"A"; else if (b==1) cout<<"B"; else cout<<"C";
if (a==2) cout<<"A"; else if (b==2) cout<<"B"; else cout<<"C";
if (a==3) cout<<"A"; else if (b==3) cout<<"B"; else cout<<"C"<<endl;}
return 0;
}