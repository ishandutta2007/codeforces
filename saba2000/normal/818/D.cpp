#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000009];

main()
{int n,A,a[100009];
cin>>n>>A;
for(int i=0; i<n; i++){
cin>>a[i];
v[a[i]].push_back(i);}
for(int i=1; i<=1000000; i++)
{if(v[i].size()<v[A].size() || i==A) continue;
int c=0;
for (int j=0; j<v[A].size(); j++)
if(v[i][j]>v[A][j]) {c=1; }
if(c) continue;
cout<<i<<endl;
return 0;
}
cout<<-1<<endl;
return 0;
}