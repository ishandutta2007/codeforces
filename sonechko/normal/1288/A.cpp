#include<bits/stdc++.h>
using namespace std;

void up()
{
    int n,d;
    cin>>n>>d;
    for (int p=0; p<=(int)sqrt(d); p++)
    if (p+(d+p)/(p+1)<=n) {cout<<"YES\n"; return;}
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}