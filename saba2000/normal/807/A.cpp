#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
pair<int,int> a[1009];
cin>>n;
for (int i=0; i<n; i++)
cin>>a[i].first>>a[i].second;

int c=0,z=0;
for (int i=0; i<n; i++)
if(a[i].first!=a[i].second) c=1;

for (int i=0; i<n; i++)
for (int j=i+1; j<n; j++)
if (a[i].first<a[j].first) z=1;
if(c==1) cout<<"rated"<<endl;
else if (z==1) cout<<"unrated"<<endl;
else cout<<"maybe"<<endl;
}