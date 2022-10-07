#include<bits/stdc++.h>
using namespace std;
int n,c[200009];
pair<int,int> a[200009],b[200009];
main()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i].first;
a[i].second=i;
}
for (int i=0; i<n; i++){
cin>>b[i].first;
b[i].second=i;}
sort(a,a+n);
sort(b,b+n);
for (int i=0; i<n; i++)
{
   // cout<<b[i].second<<" "<<a[n-i-1].first<<endl;
c[b[i].second]=a[n-1-i].first;
}
for (int i=0; i<n; i++)
    cout<<c[i]<<" ";
cout<<endl;

}