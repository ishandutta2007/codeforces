#include <list>
#include <iostream>
using namespace std;
int main ()
{list <int> l1,l2;
int n;
cin>>n;
int k1,k2;
cin>>k1;
for (int i=0; i<k1; i++)
{int a; cin>>a; l1.push_back(a);}
cin>>k2;
for (int i=0; i<k2; i++)
{int a; cin>>a; l2.push_back(a);}
for (int i=0; i<1000000; i++)
{if (l1.front()>l2.front()) {l1.push_back(l2.front()); l1.push_back(l1.front());} else
{l2.push_back(l1.front()); l2.push_back(l2.front());}
l1.pop_front();
l2.pop_front();
if (l1.size()==0) {cout<<i+1<<" "<<2<<endl;  return 0;}
if (l2.size()==0) {cout<<i+1<<" "<<1<<endl; return 0;}
}
cout<<-1<<endl;
return 0;
}