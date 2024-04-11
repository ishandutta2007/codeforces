#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 11;



int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int t=min(a,min(b-1,c-2));
    t=max(t,0);
    cout<<t*3+3<<endl;
}