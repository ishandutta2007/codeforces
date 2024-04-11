#include<bits/stdc++.h>
using namespace std;
int n,m,d[100],c[100],p[100],ans=100000;
string s;
int main()
{int a,b;
cin>>a>>b;
if (a==0 && b==0) cout<<"NO"<<endl;
else if (max(a,b)-min(a,b)<=1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}