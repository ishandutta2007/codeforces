#include<bits/stdc++.h>
using namespace std;
map<pair<int,int> ,int> M;
string t[7]={"a","b","c","d","e"};
pair<int,int> H(string s)
{
    long long C=0,C1=0,A=1e9+7,B=1e9+9,A1=952388277,B1=999999991;
    for (int i=0; i<s.size(); i++)
       {
           C=(C*A+s[i]-33)%B;
        C1=(C1*B1+s[i]-13)%A1;}
    return {C,C1};
}
map<pair<int,int>,int> M1;
string s,p;
int gen(int x,int z)
{
    if(x==s.size()) {if(M1[H(p)]==z) return 0; int xx=M[H(p)]; M1[H(p)]=z;
    return xx;}
    if(s[x]!='?'){p+=s[x]; int c=gen(x+1,z); p.pop_back(); return c;}
    int ans=0;
    for (int i=0; i<5; i++)
    {
        p+=t[i];
        //cout<<p<<endl;
        ans+=gen(x+1,z);
        p.pop_back();
    }
    return ans+gen(x+1,z);
}
main()
{
int n,m;
cin>>n>>m;
for(int i=0; i<n; i++)
{
    string s;
    cin>>s;
    M[H(s)]++;
}
for (int i=0; i<m; i++)
{
    cin>>s;
    p="";
  cout<<gen(0,i+1)<<endl;;
}
}