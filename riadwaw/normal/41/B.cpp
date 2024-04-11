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
    int n,b;
    cin>>n>>b;
    int a[2222];
    int c[2222];
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[i]=b/a[i];
        for(int j=0;j<i;j++){
            int t=(a[i]-a[j])*c[j];
            if(t>mx)
                mx=t;
        }
    }
    cout<<(mx+b);
    return 0;
}