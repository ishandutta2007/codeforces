#include<bits/stdc++.h>
using namespace std;

void up()
{
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    int len=y-x;
    if (len%(a+b)==0) cout<<len/(a+b)<<"\n"; else cout<<"-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}