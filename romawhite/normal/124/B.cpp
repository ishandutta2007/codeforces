#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
int f(string s){
    int k=0;
    for (int i=0;i<s.size();i++)
        k=10*k+int(s[i])-48;
    return k;
}
int main(){
    int n,k,l,m,i,j;
    vector <int> a;
    vector <int> b;
    vector <vector<int> > c;
    vector <string> s;
    vector <string> s1;
    string ss;
    cin>>n>>k;
    for (i=0;i<n;i++)
    {
        cin>>ss;
        s.push_back(ss);
    }
    for (i=0;i<k;i++)
        a.push_back(i);
    m=2000000000;
    do
    {
        s1.clear();
        for (i=0;i<n;i++)
        {
            ss="";
            for (j=0;j<k;j++)
                ss+=s[i][a[j]];
            s1.push_back(ss);
        }
        b.clear();
        for (i=0;i<n;i++)
            b.push_back(f(s1[i]));
        sort(b.begin(),b.end());
        m=min(m,b[n-1]-b[0]);
    }
    while (next_permutation(a.begin(),a.end()));
    cout<<m;
    return 0;
}