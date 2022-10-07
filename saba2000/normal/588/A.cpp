 #include<iostream>
using namespace std;
int p,a,s,k=100000000;
main()
{
int n;
cin>>n;
for(int i=0; i<n; i++)
{cin>>a>>p;
k=min(k,p);
s+=k*a;
    
}
cout<<s<<endl;
}