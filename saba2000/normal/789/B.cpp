#include<bits/stdc++.h>
using namespace std;
int main()
{long long b,q,l,m,k,a,ans=0;
set<long long>s;
cin>>b>>q>>l>>m;
for (int i=0; i<m; i++){
cin>>a;s.insert(a);} 
if(abs(b)>

l){cout<<0<<endl; return 0;}
if (q==0 || b==0){if(s.find(0)==s.end())cout<<"inf"<<endl; else cout<<(int)(s.find(b)==s.end())<<endl;return 0;}
if (q==1){if(s.find(b)==s.end())cout<<"inf"<<endl; else cout<<0<<endl; return 0;}
if (q==-1){if((s.find(b)==s.end())||( s.find(-b)==s.end()))cout<<"inf"<<endl; else cout<<0<<endl; return 0;}
k=b;

for (int i=0; i<=10000; i++)
{if (abs(k)>l) {cout<<ans<<endl; return 0;}
if (s.find(k)==s.end()) ans++;
k=k*q;
}
}