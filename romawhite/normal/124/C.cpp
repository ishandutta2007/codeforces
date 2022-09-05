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
    vector <int> b(500,0);
    string s;
    string ss;
    cin>>s;
    n=s.length();
    for (i=0;i<n;i++)
        ++b[int(s[i])-97];
    m=0;
    for (i=0;i<50;i++)
        if (b[i]>m)
        {
            m=b[i];
            l=i;
        }
    ss="";
    for (i=0;i<m;i++)
        ss+=char(l+97);
    for (i=0;i<n;i++)
        if (s[i]!=char(l+97)) ss+=s[i];
    vector <bool> p(n+1,0);
    //vector <int> pp;
    vector <int> a(n,-1);
    p[1]=1;
    for (i=2;i<=n;i++)
        if (!p[i])
            for (j=i*i;j<=n;j+=i)
                p[j]=1;
    /*for (i=1;i<=n;i++)
        if (!p[i])
        {
            k=i;
            for (j=i;j<n;j+=i)
                if (a[j]==-1) a[j]=k;
                else
                {
                    k=a[j];
                    for (int t=1;t<j;t++)
                        if (a[t]==i) a[t]=k;
                }
        }*/
    k=0;
    for (i=n/2+1;i<=n;i++)
        if (!p[i]) ++k;
    k=n-k-1;
    int q=0,w=n-1;
    if (k>m) {cout<<"NO";return 0;}
    cout<<"YES"<<endl;
    for (i=1;i<=n;i++)
        if (i==1 || (i>n/2 && !p[i]))
        {
            cout<<ss[w];
            --w;
        }
        else
        {
            cout<<ss[q];
            ++q;
        }
    return 0;
}