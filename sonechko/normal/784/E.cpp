#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int k1=a^b;
    int k2=c|d;
    int k3=c&b;
    int k4=d^a;
    int l1=k1&k2;
    int l2=k3|k4;
    cout<<(l1^l2)<<endl;
}