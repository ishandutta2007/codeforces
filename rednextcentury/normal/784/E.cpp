#include <bits/stdc++.h>

using namespace std;
int A[]={0,1,0,1,0,0,0,1,1,1,0,0,1,1,0,1};
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
int x=a+b*2+c*4+d*8;
    cout<<A[x]<<endl;
}