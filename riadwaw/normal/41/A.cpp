#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
#include <string.h>
using namespace std;



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    if(a==b)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}