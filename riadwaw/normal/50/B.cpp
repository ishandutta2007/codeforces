#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
typedef long long int li;
li sqr(int a){
    return (li)a*a;
}
int main ()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
#endif
    string s;
    map<char,int>a;
    li r=0;
    cin>>s;
    for(int i=0,l=s.length();i<l;i++)
        a[s[i]]++;
    for(map<char,int>::iterator i=a.begin();i!=a.end();i++){
        r+=sqr(i->second);
    }
    cout<<r;
    return 0;
}