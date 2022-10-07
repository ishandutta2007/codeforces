#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define fl fflush(stdout)
using namespace std;
int F(int l, int r)
{
while(l<r)//3 4
{int k=(l+r)/2;
cout<<1<<" "<<k<<" "<<k+1<<endl;
fl;
string a; cin>>a;
if(a=="TAK") r=k;
else l=k+1;
}
return l;

}
int n,k;
main()
{
cin>>n>>k;
int x=F(1,n);
int y=F(1,x-1);
cout<<1<<" "<<y<<" "<<x<<endl;
fl;
string a;
cin>>a;
if(a=="NIE" || x==y) y=F(x+1,n);
cout<<2<<" "<<x<<" "<<y<<endl;
return 0;
}
//5 5//+++++
//1 5