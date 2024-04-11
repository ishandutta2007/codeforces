
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
map<char,int> mp;
int main()
{
    mp['6']=6,mp['7']=7,mp['8']=8,mp['9']=9, mp['T']=10,mp['J']=11,mp['Q']=12,mp['K']=13,mp['A']=14;
    char t;
    cin>>t;
    char r1,r2,t1,t2;
    cin>>r1>>t1>>r2>>t2;
    if (mp[r1]>mp[r2] && t1==t2)
        cout<<"YES"<<endl;
    else if (t1==t && t2!=t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}