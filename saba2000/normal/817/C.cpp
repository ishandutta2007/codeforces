#include<bits/stdc++.h>
using namespace std;
long long fid(long long x)
{long long y=x,sd=0;
while(y>0){sd+=y%10; y/=10;}
return x-sd;
}
int main()
{long long n,s;
cin>>n>>s;
if(fid(n)<s) {cout<<0<<endl; return 0;}
long long x=1,y=n; 
while(x<y)
{long long mid=(x+y)/2;
//cout<<mid<<" "<<fid(mid)<<endl;
if(fid(mid)>=s) y=mid;
else x=mid+1;}
cout<<n-x+1<<endl;

}