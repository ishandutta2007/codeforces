#include<bits/stdc++.h>
using namespace std;

int n,c[100009],a[100009],b[100009];
vector<int> t[100009];
bool check(int p)
{for (int i=1; i<n; i++)
{if (a[i]!=p && b[i]!=p && c[a[i]]!=c[b[i]]) return 0;
}
return 1;
}
int main()
{cin>>n; int u,v;
for (int i=1; i<n; i++)
{cin>>u>>v;u--;v--;
t[u].push_back(v);
t[v].push_back(u);
a[i]=u; b[i]=v;
}

for (int i=0; 
i<n; i++)
cin>>c[i];
for (int i=1; i<n; i++)
{if (c[a[i]]==c[b[i]])  continue;
if (check(a[i])==0) {if (check(b[i])==1) {cout<<"YES\n"<<b[i]+1<<endl; return 0;}
 else {cout<<"NO"<<endl; return 0;}} else {cout<<"YES\n"<<a[i]+1<<endl;  return 0;}
}
cout<<"YES"<<endl<<1<<endl;
}