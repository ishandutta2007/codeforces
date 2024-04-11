#include<iostream>
using namespace std;
int a1,a2,a3,b1,b2,b3,n;
int main()
{
    cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
    if((a1+a2+a3+4)/5+ (b1+b2+b3+9)/10 <= n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}