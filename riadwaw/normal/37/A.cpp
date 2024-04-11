#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a,mx=0,c=0;
    cin>>a;
    int x[1010];
    for(int i=0;i<1010;i++){
        x[i]=0;
    }
    for(int i=0;i<a;i++){
        int t;
        cin>>t;
        if(!x[t])
            c++;
        x[t]++;
        if(x[t]>mx)
            mx=x[t];
    }
    cout<<mx<<' '<<c;
    return 0;
}