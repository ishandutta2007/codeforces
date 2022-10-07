#include<bits/stdc++.h>
using namespace std;
vector<int> a,b,c;
int n,r[100009],R[100009],Z[100009];
priority_queue<pair<int,int> > q;
main()
{cin>>n;
for(int i=0; i<n; i++)
scanf("%d",&r[i]);
sort(r,r+n);
int s=0;
for(int i=0; i<n; i++)
if(r[i]!=r[i+1] || i==n-1){
    q.push(make_pair(s+1,r[i]));s=0;}
else s++;
while(q.size()>=3)
{pair<int,int> X=q.top(); q.pop();
pair<int,int> Y=q.top(); q.pop();
pair<int,int> Z=q.top(); q.pop();
int e=X.second,w=Y.second,v=Z.second;
if(e<w) swap(e,w);
if(e<v) swap(e,v);
if(w<v) swap(v,w);
a.push_back(e);
b.push_back(w);
c.push_back(v);
if(X.first>1) q.push(make_pair(X.first-1,X.second));
 if(Y.first>1) q.push(make_pair(Y.first-1,Y.second));
if(Z.first>1) q.push(make_pair(Z.first-1,Z.second));}
cout<<a.size()<<endl;
for(int i=0; i<a.size(); i++)
cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;

}