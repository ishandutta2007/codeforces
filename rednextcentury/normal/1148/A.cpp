#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long len = c*2;
    cout<< len + min(min(a,b)*2+1,a+b)<<endl;
}