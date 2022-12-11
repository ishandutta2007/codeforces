#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k,a,b;
    cin>>k>>a>>b;
    cin>>s;
    int n=s.length();
    if ((a*k>n)||(b*k<n)) {
        cout<<"No solution";
        return 0;
    }
    int sr=n/k,nn=n%k,col=0;
    for (int i=1;i<=(k-nn);i++){
        for (int j=1;j<=sr;j++)
            cout<<s[col++];
        cout<<'\n';
    }
    for (int i=(k-nn+1);i<=k;i++){
        for (int j=1;j<=sr+1;j++)
            cout<<s[col++];
        cout<<'\n';
    }
    return 0;
}