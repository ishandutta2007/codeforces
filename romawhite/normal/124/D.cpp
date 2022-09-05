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
    int x3,y3,x4,y4,a,b,x1,x2,y1,y2;
    cin>>a>>b>>x1>>y1>>x2>>y2;
    if (x1+y1>=0)
    x3=(x1+y1)/(2*a);
    else 
    x3=(x1+y1)/(2*a)-1;
    if (x1-y1>=0)
    y3=(x1-y1)/(2*b);
    else 
    y3=(x1-y1)/(2*b)-1;
    if (x2+y2>=0)
    x4=(x2+y2)/(2*a);
    else 
    x4=(x2+y2)/(2*a)-1;
    if (x2-y2>=0)
    y4=(x2-y2)/(2*b);
    else 
    y4=(x2-y2)/(2*b)-1;
    k=max(abs(x3-x4),abs(y3-y4));
    cout<<k;
    return 0;
}