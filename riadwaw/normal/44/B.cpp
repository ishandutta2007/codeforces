#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
using namespace std;
int main(){
    //freopen("input.txt","r",stdin);
    int n,a,b,c,cnt=0;
    cin>>n>>a>>b>>c;
    for (int i=0;i<=c;i++){
        int mx=min(b,n-i*2);
        int mn=max(n-i*2-a/2,0);
        if(mx>=mn)
            cnt+=mx-mn+1;
    }
    cout<<cnt;
    return 0;
}