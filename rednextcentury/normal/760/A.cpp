#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int len[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    fast
    int m,d;
    cin>>m>>d;
    int x=len[m]-(8-d);
    cout<<1+(x/7+(x%7>0))<<endl;
}