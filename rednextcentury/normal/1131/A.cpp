#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    long long ret = 2*(w1+h1+2)+2*(w2+h2+2);
    ret-=min(w1,w2)*2+4;
    cout<<ret<<endl;
}