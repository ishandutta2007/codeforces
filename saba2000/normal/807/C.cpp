#include<bits/stdc++.h>
using namespace std;
int main()
{int T;
cin>>T;
for (int i=0; i<T; i++){
long long x,y,p,q;
cin>>x>>y>>p>>q;
if(p==0) {if(x==0) cout<<0<<endl; else cout<<-1<<endl; continue;}
long long X=x-x%p+p;
if(x%p==0) X-=p;
X/=p;
long long Y=y-y%q+q;
if(y%q==0) Y-=q;
Y/=q;
//cout<<X<<" "<<Y<<endl;
long long a=max(X,Y);
if(a*(p-q)<=x-y) cout<<a*q-y<<endl;
else if(p>=q){cout<<-1<<endl;}
else {a=(y-x+q-p-1)/(q-p); cout<<a*q-y<<endl;}
}
}

//
//3 10
//1 2
//(x-y)/(p-q)