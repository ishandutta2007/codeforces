#include<iostream>
#include<map>
using namespace std;
long long n,a,b,c,ans1=0,ans2,ans3=0,ans4,ans5;
struct P{int x,y;};
bool operator <(P u, P v)
{if (u.x != v.x) return u.x<v.x; else return u.y<v.y;  }
P p,q;
map <P,int> m1,m2;
main()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>a>>b>>c;
if (a<b) swap(a,b);if (a<c) swap(a,c);if (b<c) swap(b,c);
p.x=a; p.y=b;
//cout<<a<<" "<<b<<" "<<c<<endl<<endl;
//cout<<m1[p]<<"  "<<m2[p]<<"  "<<endl;
if (min(min(a,b),m1[p]+c)>ans3 && m1[p]!=0) 
{ans3=min(min(a,b),m1[p]+c); ans4=i+1; ans5=m2[p];}
if (m1[p]<c) {m1[p]=c; m2[p]=i+1;} 
if (c>ans1) {ans1=c; ans2=i+1;}
}


if (ans3>ans1)
 cout<<2<<endl<<ans4<<" "<<ans5<<endl; else
cout<<1<<endl<<ans2<<endl;
}