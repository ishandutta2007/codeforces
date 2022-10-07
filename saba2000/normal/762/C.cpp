#include<bits/stdc++.h>
using namespace std;
int p[100009],q[100009],k=0,l,r,ans=1000000000;
int main()
{string a,b;
cin>>a>>b;
 for (int i=0; i<a.size(); i++)
 if (b[k]==a[i]) {p[k]=i+1; k++;}
 if (p[b.size()-1]!=0) {cout<<b<<endl; return 0;}
 int k=b.size()-1;
for (int i=a.size()-1; i>=0; i--)
if (b[k]==a[i]) {q[k]=i+1; k--;}
for (int i=0; i<b.size(); i++)
{if (i!=0 && p[i-1]==0) continue;
int x=i,y=b.size()-1;
while(x<y)
{int z=(x+y)/2;
if (p[i-1]<q[z+1]) y=z;
else x=z+1;
}
//cout<<i<<" "<<x<<endl;
if (x-i<ans) {ans=x-i; l=i; r=x;}
}
if (ans==b.size()-1) cout<<'-'<<endl; else{
for (int i=0; i<b.size(); i++)
if (i>=l && i<=r) continue; else cout<<b[i];}

}
//a^a==x
//11 -- 1
//2 -- 0