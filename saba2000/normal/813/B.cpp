#include<bits/stdc++.h>
using namespace std;
int main()
{long long x,y,l,r;
cin>>x>>y>>l>>r;
vector<long long> z,t;
z.push_back(1);
while(z[z.size()-1]<(2*r+7)/x){if(z[z.size()-1]*x>r+1) break; z.push_back(z[z.size()-1]*x);}
t.push_back(1);
while(t[t.size()-1]<(2*r+7)/y) {if(t[t.size()-1]*y>r+1) break;t.push_back(t[t.size()-1]*y);}
vector<long long> u;
long long ans=0;
for (int i=0; i<z.size(); i++)
for (int j=0; j<t.size(); j++)
u.push_back(z[i]+t[j]);
u.push_back(r+1);
u.push_back(0);
sort(u.begin(),u.end());
for (int i=0; i<u.size()-1; i++)
ans=max(ans,min(u[i+1]-1,r)-max(l,u[i]+1)+1);

cout<<ans<<endl;
}