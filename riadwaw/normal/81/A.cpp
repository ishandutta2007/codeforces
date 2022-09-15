#include <iostream>
#include <vector>
using namespace std;
int main(){
string s;cin>>s;
vector<char> v;
for(int i=0;i<s.length();++i)
if(v.size() && v.back()==s[i])
v.pop_back();
else
v.push_back(s[i]);
for(int i=0;i<v.size();++i)
cout<<v[i];
return 0;
}