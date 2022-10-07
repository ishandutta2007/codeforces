#include<iostream>
using namespace std;
main()
//INETEEN
{string s;int N=0,I=0,E=0,T=0,ans=0;
cin>>s;
for (int i=0; i<s.size(); i++)
{if (s[i]=='n') N++;
if (s[i]=='t') T++;
if (s[i]=='e') E++;
if (s[i]=='i') I++;}
N--;
while(N>1 && T>0 && E>2 && I>0)
{++ans;--I;--N;--E;--T;--E;--E;--N;}
cout<<ans<<endl;
}