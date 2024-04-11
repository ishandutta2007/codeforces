#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1000 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<n/100+(n%100)/20+(n%20)/10+(n%10)/5+n%5<<endl;
}