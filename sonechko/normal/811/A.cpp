#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=100000; i++)
    {
        if (i%2==1) n-=i; else m-=i;
        if (n<0) {cout<<"Vladik"<<endl; return 0;}
        if (m<0) {cout<<"Valera"<<endl; return 0;}
    }
}