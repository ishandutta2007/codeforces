#include<bits/stdc++.h>
using namespace std;
main()
{long long n,k;cin>>n>>k;
long long r=n/2-(n/2)%(k+1);
long long w=r/(k+1);
cout<<w<<" "<<k*w<<" "<<n-(k+1)*w<<endl;
    
}