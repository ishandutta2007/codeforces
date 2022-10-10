#include <bits/stdc++.h>
using namespace std;

int main()
{
string s;
cin >> s;
for(auto &c : s)
if(c==',')
c=' ';
stringstream in(s);
int x;
vector<int> v;
while(in>>x)
v.push_back(x);
sort(v.begin(), v.end());
v.erase(unique(v.begin(),v.end()),v.end());
v.push_back(-1);
string res;
int cur=v[0], pre=v[0];
for(int i=1;i < v.size(); i++) {
if(v[i]==v[i-1]+1)
cur++;
else {
if(res.size())
res+=',';
res+=to_string(pre);
if(pre != cur) {
res+='-';
res+=to_string(cur);
}
cur=pre=v[i];
}
}
cout<<res<<'\n';
}