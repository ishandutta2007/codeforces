#include<bits/stdc++.h>
using namespace std;
int n,m,k,a;
set<int> S;
int main()
{
cin>>n>>m;
for (int i=0; i<m; i++)
{S.clear();
int z=0;
cin>>k;
for (int j=0; j<k; j++)	
{cin>>a;
S.insert(a);
if (S.find(-a)!=S.end()) z=1;
}
if (z==0) {cout<<"YES"<<endl; return 0;}
}
cout<<"NO"<<endl;
}