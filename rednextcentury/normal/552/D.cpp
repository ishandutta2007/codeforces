#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[5000],y[5000];
map<pair<int,int> ,ll > num;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    ll ret=0;
    for (int i=1;i<=n;i++) {
        num.clear();
        for (int j=1;j<=n;j++) {
            if (i==j)continue;
            int X = y[i]-y[j];
            int Y = x[i]-x[j];
            int sign = (X<0) ^ (Y<0);
            if (X==0)num[{1,0}]++;
            else if (Y==0)num[{0,1}]++;
            else {
                int G = __gcd(X,Y);
                X/=G;
                Y/=G;
                X=abs(X);
                Y=abs(Y);
                if (sign)X=-X;
                num[{X,Y}]++;
            }
        }

        ll cur=0;
        for (auto p:num){
            cur+=p.second*(p.second-1)/2;
        }
        ret+=cur;
    }
    cout<<n*(n-1)*(n-2)/6 - (ret/3)<<endl;
}