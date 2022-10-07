#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,p[100],t[100],c,k,a1,a2;

main()
{cin>>n>>c;
for (int i=0; i<n; i++)
cin>>p[i]; 
for (int i=0; i<n; i++)
cin>>t[i];
for (int i=0; i<n; i++)
{k+=t[i];
a1+=max(0,p[i]-c*k);}
k=0;
for (int i=n-1; i>=0; i--)
{k+=t[i];
a2+=max(0,p[i]-c*k);}
if (a1>a2) cout<<"Limak"<<endl;
else if (a1==a2) cout<<"Tie"<<endl;
else  cout<<"Radewoosh"<<endl;


}