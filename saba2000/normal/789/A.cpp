#include<bits/stdc++.h>
using namespace std;
int main()
{long long n,k,ans=0,a;
cin>>n>>k;
for (int i=0; i<n; i++)
{cin>>a;
ans+=(a+k-1)/k;
}
cout<<(ans+1)/2<<endl;
}