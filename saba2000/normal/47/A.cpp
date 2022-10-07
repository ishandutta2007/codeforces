#include <iostream>
using namespace std;int main (){int n,b=1; cin>>n; for (int i=1; i<=500; i+=b) {b++; if(n==i) {cout<<"YES"; return 0;}} cout<<"NO"; return 0;}