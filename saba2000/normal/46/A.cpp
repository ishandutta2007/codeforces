#include <iostream>
using namespace std;int main (){int n,b=1; cin>>n;for (int i=2; b<n; i+=b){b++; cout<<(i+n-1)%n+1<<" ";}return 0;}