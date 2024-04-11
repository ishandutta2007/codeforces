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
        long double angle = 180.0 * (n-2);
        angle /= n;
        angle = 180.0 - angle;
        angle = angle * acos(-1);
        angle /= 180.0;
        long double ret = 1;
        for (int i=0;i<(n-4)/4;i++){
            ret = ret + 2*sin(angle*(i+1));
        }
        cout<<setprecision(10)<<fixed<<ret<<endl;
    }
}