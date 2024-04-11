#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int cnt[1111111];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;
    cin>>a>>b;
    if (b<a)b*=10;
    if (a==b)cout<<a*10<<' '<<a*10+1<<endl;
    else if (b-a==1)cout<<a<<' '<<b<<endl;
    else cout<<-1<<endl;
}