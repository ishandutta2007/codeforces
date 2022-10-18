#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k1=0,k2=0,k3=0,k4=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='n') k1++; else
        if (s[j]=='i') k2++; else
        if (s[j]=='e') k3++; else
        if (s[j]=='t') k4++;
    for (int d=100; d>=0; d--)
    {
        int kk1=d*2+1,kk2=d,kk3=d*3,kk4=d;
        if (kk1<=k1&&kk2<=k2&&kk3<=k3&&kk4<=k4)
        {
            cout<<d<<endl; return 0;
        }
    }
    cout<<0<<endl;
}