#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int ret=0;
    if (b>=a+1 && c>=a+2)
        ret=max(ret,a+a+a+3);
    else if (a>=b-1 && c>=b+1)
        ret=max(ret,b+b-1+b+1);
    else if (a>=c-2 && b>=c-1)
        ret=max(ret,c+c-2+c-1);
        cout<<ret<<endl;
}