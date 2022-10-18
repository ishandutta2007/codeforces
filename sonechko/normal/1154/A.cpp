#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k1,k2,k3,k4;
    cin>>k1>>k2>>k3>>k4;
    if (k2>=k1&&k2>=k3&&k2>=k4) swap(k1,k2);
    if (k3>=k1&&k3>=k2&&k3>=k4) swap(k1,k3);
    if (k4>=k1&&k4>=k2&&k4>=k3) swap(k1,k4);
    cout<<k1-k2<<" "<<k1-k3<<" "<<k1-k4<<endl;
}