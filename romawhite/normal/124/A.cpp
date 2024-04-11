#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
int main(){
    int d,c,n,a,b;
    cin>>n>>a>>b;
    c=n-a;
    d=min(b+1,c);
    cout<<d;
    return 0;
}