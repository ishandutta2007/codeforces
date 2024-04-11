#include<bits/stdc++.h>
#include<set>
using namespace std;
int n,c[200009],t[200009],a[200009],cur=0;
set<pair<int,int> > s;
main()
{cin>>n;
for (int i=1; i<=n; i++)
{cin>>t[i];
s.insert(make_pair(t[i],i));
 std::set<pair<int,int> >::iterator d;
 pair<int,int> P;
 d=s.upper_bound(make_pair(t[i]-1440,10000000)); P=*d;
 int D=P.second;
  d=s.upper_bound(make_pair(t[i]-90,10000000));  P=*d;
int H=P.second;
a[i]=min(a[i-1]+20,min(a[D-1]+120,a[H-1]+50));
cout<<a[i]-a[i-1]<<endl;
}
}