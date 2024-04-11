
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int M = 1e6 + 100;
const int inf  = 1e9 + 7;
int f[M],val[M];

void getfill(string s)
{
    int sz = s.size();
    memset(f,0,sizeof(f));  //
    for(int i=1;i<sz;i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j]) j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}

int main()
{
    //ios::sync_with_stdio(false) ;
    string s;cin >> s;getfill(s);
    int sz = s.size(), i,max_ = 0;
    for(i = 1; i<sz; i++) val[f[i]] = 1;
    while(!val[sz]&&sz)  sz=f[sz];
    if(!sz) cout << "Just a legend";
    else{
        for(i = 0; i <sz; i++) cout<<s[i];
    }
}