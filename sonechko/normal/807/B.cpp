#include<bits/stdc++.h>
using namespace std;
bool good(int s, int t)
{
    int i=(s/50)%475;
    for (int j=1; j<=25; j++)
    {
        i=(i*96+42)%475;
        if (t==26+i) return true;
    }
    return false;
}
int main()
{
    int p,x,y;
    cin>>p>>x>>y;
    for (int i=0; i<=1000000; i++)
    {
        if (x-i*50>=y&&good(x-i*50,p)) {cout<<0<<endl; return 0;}
    }
    for (int i=0; i<=1000000; i++)
    {
        if (x+i*100>=y&&good(x+i*100,p)) {cout<<i<<endl; return 0;}
        if (x+i*100-50>=y&&good(x+i*100-50,p)) {cout<<i<<endl; return 0;}
    }
}