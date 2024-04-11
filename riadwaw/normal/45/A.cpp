#include<stdio.h>
#include<string.h>
#include <string>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include <map>

using namespace std;
string go(string a){
        if(a==string("January"))
            return string("February");
        if(a==string("February"))return string("March");
        if(a== string("March"))return string("April");
        if(a== string("April"))return string("May");
        if(a==string("May"))return string("June");
        if(a==string("June"))return string("July");
        if(a==string("July"))return string("August");
        if(a==string("August"))return string("September");
        if(a==string("September"))return string("October");
        if(a==string("October"))return string("November");
        if(a==string("November"))return string("December");
        if(a==string("December"))return string("January");
        return string();
}
int main()
{
    //freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    string a;
    int n;
    cin>>a>>n;
    n%=12;
    for(int i=0;i<n;i++)
        a=go(a);
    cout<<a;
    return 0;
}