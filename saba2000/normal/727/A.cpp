
#include<iostream>
using namespace std;
main()
{int x,b; string a="";
cin>>x>>b; 
while (b>0 && b!=x)
{if (b%10==1) {b/=10;a='1'+a;}
else if (b%2==0) {b/=2;a='0'+a;}
else {cout<<"NO"<<endl; return 0;}
 } 
 if(b==0) {cout<<"NO"<<endl; return 0;}
 cout<<"YES"<<endl;
 cout<<a.size()+1<<endl<<x<<" ";
 for (int i=0; i<a.size();i++)
 {if (a[i]=='0'){x*=2; cout<<x<<" ";} else
{x=x*10+1; cout<<x<<" ";}
}

}