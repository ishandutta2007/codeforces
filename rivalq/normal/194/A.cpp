#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int i=0;
    while(3*(n-i)>(k-2*i)) i++;
    cout<<i<<endl;
}