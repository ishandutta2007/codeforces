#include<bits/stdc++.h>
using namespace std;
long long n,x,y,v;
int main(){
    cin>>n>>x>>y;
    v=y*n/100+(y*n%100!=0);
    if(x>=v)
        cout<<0;
    else
        cout<<v-x;
}