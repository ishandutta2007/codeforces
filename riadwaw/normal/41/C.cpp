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
    string a;
    cin>>a;
    bool at=true;
    for(int i=1;i+2<a.length();i++){
        if(at && a[i]=='a' && a[i+1]=='t'){
            a=a.substr(0,i)+'@'+a.substr(i+2);
            at=false;
        }
        else if(i+3<a.length() && a[i]=='d' && a[i+1]=='o' && a[i+2]=='t')
            a=a.substr(0,i)+'.'+a.substr(i+3);
    }
    cout<<a;
    return 0;
}