#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    if(x==1) cout<<1; else
    if(x==3) cout<<5;else
    if(x<=5) cout<<3;else
    if(x<=13)cout<<5;else
    if(x<=25)cout<<7;else
    if(x<=41)cout<<9;else
    if(x<=61)cout<<11;else
    if(x<=85)cout<<13;else
    cout<<15;
    return 0;
}