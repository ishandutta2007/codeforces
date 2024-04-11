#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
long long e[100009];
vector<long long> v;
vector<pair<long long,long long> > x,y;;
long long a,b,w,h,n;
bool check (long long p)
{v.clear(); x.clear(); y.clear();
for (long long i=n-1; i>n-1-p; i--)
v.push_back(e[i]);
long long k=v.size();
x.push_back(make_pair(1,1));
vector<pair<long long,long long> > d;
for (long long i=0; i<k/2; i++)
{ d.clear();
for (long long j=0; j<x.size(); j++){
if(x[j].F<1000000)d.push_back(make_pair(x[j].F*v[i],x[j].S)); else d.push_back(make_pair(x[j].F,x[j].S));
if(x[j].S<1000000) d.push_back(make_pair(x[j].F,x[j].S*v[i]));  else d.push_back(make_pair(x[j].F,x[j].S));
}
x=d;}
y.push_back(make_pair(1,1));
for (long long i=k/2; i<k; i++)
{ d.clear();
for (long long j=0; j<y.size(); j++){
if(y[j].F<1000000)d.push_back(make_pair(y[j].F*v[i],y[j].S)); else d.push_back(make_pair(y[j].F,y[j].S));
if(y[j].S<1000000) d.push_back(make_pair(y[j].F,y[j].S*v[i])); else d.push_back(make_pair(y[j].F,y[j].S));
}
y=d;}vector<pair<long long,long long> > l;
sort(y.begin(),y.end());
//for(long long i=0; i<x.size(); i++)
//cout<<x[i].F<<" "<<x[i].S<<endl;
//cout<<endl;
//for(long long i=0; i<y.size(); i++)
//cout<<y[i].F<<" "<<y[i].S<<endl;
long long X=(a+w-1)/w,Y=(b+h-1)/h;
for (long long i=0; i<x.size(); i++)
l.push_back(make_pair((X+x[i].F-1)/x[i].F,(x[i].S+Y-1)/x[i].S));
sort(l.begin(),l.end());long long r=y.size()-1,u=0;
for (long long i=l.size()-1; i>=0; i--)
{//cout<<l[i].F<<" "<<l[i].S<<endl;
//system("pause");
while(r>=0 && y[r].F>=l[i].F) {u=max(u,y[r].S); r--;}
//cout<<u<<endl;
if(u>=l[i].S) return true;}
l.clear();
//vector<pair<long long,long long> > l;
X=(b+w-1)/w,Y=(a+h-1)/h;
for (long long i=0; i<x.size(); i++)
l.push_back(make_pair((X+x[i].F-1)/x[i].F,(x[i].S+Y-1)/x[i].S));
sort(l.begin(),l.end()); r=y.size()-1,u=0;
for (long long i=l.size()-1; i>=0; i--)
{//cout<<l[i].F<<" "<<l[i].S<<endl;
while(r>=0 && y[r].F>=l[i].F) {u=max(u,y[r].S); r--;}
//cout<<u<<endl;
if(u>=l[i].S) return true;}

return false;

}
main()
{//cout<<check(10)<<endl;
cin>>a>>b>>w>>h>>n;
for (long long i=0; i<n; i++)
cin>>e[i];
sort(e,e+n);
//cout<<check(10)<<endl;
//system("pause");
if((w>=a && h>=b ) || (w>=b && h>=a)) {cout<<0<<endl; return 0;}
long long x=1,y=min(n,(long long)34);
while(x<y)
{long long z=(x+y)/2;
bool k=check(z);
if(k) y=z;
else x=z+1;
}

if(check(x)) cout<<x<<endl;
else cout<<-1<<endl;

}