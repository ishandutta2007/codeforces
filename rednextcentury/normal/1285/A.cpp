#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int L=0,R=0;
    int n;string s;
    cin>>n>>s;
    for (auto x:s){
        if (x=='L')L++;
        if (x=='R')R++;
    }
    cout<<L+R+1<<endl;
}