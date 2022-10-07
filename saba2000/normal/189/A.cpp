  #include<iostream>
using namespace std;
main()
{
int n,a,b,c,ans=0;
cin>>n>>a>>b>>c;
for (int i=0; i<=n; i++)
for (int j=0; j<=n; j++)
if ((n-a*i-b*j)%c==0 && a*i+b*j<=n ) ans=max(ans,i+j+(n-a*i-b*j)/c);
cout<<ans<<endl;
}