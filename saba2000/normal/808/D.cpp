#include<bits/stdc++.h>
using namespace std;
main()
{
long long n,w,a[100009];
cin>>n;
for (int i=0; i<n; i++){
cin>>a[i];
w+=a[i];}
if(w%2==1) {cout<<"NO"<<endl; return 0;}
w/=2;
set<long long> x,y;long long p=0;
for (int i=0; i<n; i++)
{p+=a[i]; x.insert(a[i]); if(p==w || x.find(p-w)!=x.end()) {cout<<"YES"<<endl; return 0;}}

p=0; x.clear();
for (int i=n-1; i>=0; i--)
{p+=a[i]; x.insert(a[i]); if(p==w || x.find(p-w)!=x.end()) {cout<<"YES"<<endl; return 0;}
}
cout<<"NO"<<endl;
}