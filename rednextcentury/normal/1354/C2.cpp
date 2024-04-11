#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        n = n*2;
        long double pi = acos(-1);
        long double N = n;
        long double ret = 1.0 / (2*sin(pi/(2*N)));
        cout<<setprecision(10)<<fixed<<ret<<endl;
    }
}