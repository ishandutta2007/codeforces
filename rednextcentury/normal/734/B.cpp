#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    long long n2,n3,n5,n6;
    cin>>n2>>n3>>n5>>n6;
    long long num1=min(n2,min(n5,n6));
    n2-=num1,n5-=num1,n6-=num1;
    long long num2=min(n2,n3);
    cout<<num1*256+num2*32<<endl;
}