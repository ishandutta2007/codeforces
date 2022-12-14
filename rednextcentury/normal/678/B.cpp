#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isLeap(int y){
    bool leap=0;
    if (y%400==0)leap=1;
    else if (y%4==0 && y%100!=0)leap=1;
    return leap;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll y;
    cin>>y;
    bool leap = 0;
    int start=0;
    ll tot=365+isLeap(y);
    for (ll x=y+1;;x++){
        if (isLeap(x)==isLeap(y) && tot%7==0){
            cout<<x<<endl;
            return 0;
        }
        tot+=365+isLeap(x);
    }
}