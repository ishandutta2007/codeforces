#include<iostream>
#include<string>
using namespace std;
int n,p,q,ans,t;
string k;
main()
{
cin>>n;
getline(cin,k);
getline(cin,k);
for (int i=0; i<k.length(); i++)
{if(p>0 || k[i]!=' ') p++;
else t++;
if(p>n) {cout<<"Impossible"<<endl; return 0;}
if(k[i]=='.' || k[i]=='!' || k[i]=='?')
{if(q+p+t>n) {ans++; q=p; p=0; t=0;} 
else {q+=p+t; p=0; t=0;}}
}
if(q>0) ans++;
if (q<=n) cout<<ans<<endl;
else cout<<"Impossible"<<endl;
}