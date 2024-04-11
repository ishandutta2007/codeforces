#include<bits/stdc++.h>
#define int long long
using namespace std;
int w,h;
priority_queue<pair<int,int> > qw,qh;
set<int> Sw,Sh;
vector<int> nw[200009],nh[200009];
int m;
main()

{cin>>w>>h;
cin>>m;
qw.push(make_pair(w,0));
qh.push(make_pair(h,0));
Sw.insert(0);
Sh.insert(0);
for(int i=0; i<m; i++)
{char d; int x;
cin>>d>>x;
if(d=='V')
{int l=-*(Sw.upper_bound(-x));
nw[l].push_back(x);
Sw.insert(-x);}
else{int l=-*(Sh.upper_bound(-x));
//cout<<l<<endl;
nh[l].push_back(x);
Sh.insert(-x);}
while(nw[qw.top().second].size()!=0)
{int a=qw.top().second,b=qw.top().first+a; qw.pop();int s=a;
while(nw[a].size()) {qw.push(make_pair(nw[a].back()-s,s)); s=nw[a].back(); nw[a].pop_back();}
 qw.push(make_pair(b-s,s))  ;
}
while(nh[qh.top().second].size()!=0)
{int a=qh.top().second,b=qh.top().first+a; qh.pop();int s=a;
while(nh[a].size()) {qh.push(make_pair(nh[a].back()-s,s)); s=nh[a].back(); nh[a].pop_back();}
    qh.push(make_pair(b-s,s))  ;
}
cout<<qw.top().first*qh.top().first<<endl;
}
}