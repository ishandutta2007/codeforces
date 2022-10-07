#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{
    vector <pair<string,string> >v;
    vector <string> s;
    int n,m;
    string p,k,j;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {cin>>p>>k; v.push_back(make_pair(p,k));
    if (p.length()>k.length()) s.push_back(k);
    else s.push_back(p);
}
    for (int i=0; i<n; i++) {
    cin>>j;
    for (int d=0; d<m; d++)
    if (j==v[d].first || j==v[d].second) cout<<s[d]<<" ";
}
return 0;
}