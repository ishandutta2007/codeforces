#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<4*(sqrt(a*b/c)+sqrt(b*c/a)+sqrt(a*c/b))<<endl;
}