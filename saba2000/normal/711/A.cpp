#include<iostream>
using namespace std;
main()
{string s[1009];
int n,p=0;;
cin>>n;
for(int i=0; i<n; i++)
{cin>>s[i];
    string x=s[i];
    if(x[0]=='O' && x[1]=='O' && p==0) {x[0]='+'; x[1]='+'; p=1;}
    if(x[3]=='O' && x[4]=='O' && p==0) {x[3]='+'; x[4]='+'; p=1;}
    s[i]=x;
}
if(p==0) cout<<"NO"<<endl; else{cout<<"YES"<<endl;
for (int i=0; i<n; i++)
cout<<s[i]<<endl;
}
}