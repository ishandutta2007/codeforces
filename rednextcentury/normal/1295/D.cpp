#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define mid (l+r)/2
//#define L (x<<1)
//#define R (L+1)

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll g = __gcd(a,b);
        ll L = a/g;
        ll R = (a+b)/g;
        if ((a+b)%g == 0)R--;
        vector<ll> vec;
        ll A = b/g;
        for (ll i=2;i*i<=A;i++) {
            if (A%i==0){
                while(A%i==0)A/=i;
                vec.push_back(i);
            }
        }
        if (A>1){
            vec.push_back(A);
        }
        int n = vec.size();
        ll ret=0;

        for (int i=0;i<(1<<n);i++) {
            int num=0;
            ll v=1;
            for (int j=0;j<n;j++) {
                if ((1<<j)&i){
                    num++;
                    v=v*vec[j];
                }
            }
            if (num==0)continue;
            if (num%2)ret += (R/v - (L-1)/v);
            else ret-=(R/v - (L-1)/v);
        }
        cout<<(R-L+1 - ret)<<endl;
    }
}