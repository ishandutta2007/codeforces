#include<bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
int n,c,d;
vector<pair<int,int> > a,b;
vector<int> A,B;
int bs(int p)
{if(A.size()==0) return -1;
int x=0,y=A.size()-1;
while(x<y)//3 4 3 
{int z=(x+y+1)/2;
if(a[z].F>p) y=z-1;
else x=z;
}
if(a[x].F<=p) return A[x];
else return -1;
}
int cc=0,dd=0;
int main()
{cin>>n>>c>>d;
for (int i=0; i<n; i++)
{int x,y; char z; cin>>x>>y>>z;
if(z=='C') {a.push_back(MP(y,x)); if(y<=c && x>cc) cc=x;}
else {b.push_back(MP(y,x)); if(y<=d && x>dd) dd=x;}}
int ans=0;
if(cc>0 && dd>0) ans=cc+dd;
sort(a.begin(),a.end());
for (int i=0; i<a.size(); i++)
{int k=bs(c-a[i].F);
if(k!=-1) ans=max(ans,k+a[i].S);
if(A.size()==0) A.push_back(a[i].S); else A.push_back(max(A[A.size()-1],a[i].S));}
a=b;
A.clear(); c=d;

sort(a.begin(),a.end());
for (int i=0; i<a.size(); i++)
{int k=bs(c-a[i].F);
if(k!=-1) ans=max(ans,k+a[i].S);
if(A.size()==0) A.push_back(a[i].S); else A.push_back(max(A[A.size()-1],a[i].S));}
cout<<ans<<endl;
}