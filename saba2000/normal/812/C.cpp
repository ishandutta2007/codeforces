#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
main(){
        long long n,S,a[100009];
       cin>>n>>S;
        for (long long i=0; i<n; i++)
        cin>>a[i];
        long long x=0,y=n;
        long long s=0;
        while(x<y)
        {
long long z=(x+y+1)/2;
vector<long long> b;
for (long long i=0; i<n; i++)
b.push_back(a[i]+z*(i+1));
sort(b.begin(),b.end());
s=0;
for (long long i=0; i<z; i++)
s+=b[i];
if(s<=S) x=z;
else y=z-1;
}
vector<long long> b;
s=0;
for (long long i=0; i<n; i++)
b.push_back(a[i]+x*(i+1));
sort(b.begin(),b.end());
for (long long i=0; i<x; i++)
s+=b[i];
cout<<x<<" "<<s<<endl;
}