#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000009];
long long ans=0;
main()
{
int n;
cin>>n;
for(int i=0; i<n; i++)
{int a;
    cin>>a;
    v[a].push_back(i);
}
for(int i=0; i<=1000000; i++)
    for (int j=0; j<v[i].size(); j++)
{
    long long a,b;
    if(j==0)  a=v[i][j]+1; else a=v[i][j]-v[i][j-1];
    ans+=a*(n-v[i][j])
    ;
}
printf("%.8f",(double)(2*ans-(long long)n)/(double)n/(double)n);
}