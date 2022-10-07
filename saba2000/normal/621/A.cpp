#include<iostream>
using namespace std;
main()
{long long n,k=0,a,s=0,an=0;
cin>>n;
for (int i=0; i<n; i++)
{cin>>a; if (a%2==1) {s++; if (k==0) k=a; else k=min(k,a);} an+=a;}
if (s%2==1) cout<<an-k; else cout<<an<<endl; 
}