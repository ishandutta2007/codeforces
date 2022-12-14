#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MX = 1e17;
vector<pair<ll,ll> > vec;
ll x0, Y0, ax, ay, bx, by;
void gen_points(){
    cin>>x0>>Y0>>ax>>ay>>bx>>by;
    vec.emplace_back(x0, Y0);
    while(1){
        if (MX/x0 < ax || MX/Y0 < ay) return;
        x0 = x0*ax + bx;
        Y0 = Y0*ay + by;
        vec.emplace_back(x0, Y0);
    }
}
ll sx,sy,T;

ll dist(pair<ll,ll> A,pair<ll,ll> B){
    return llabs(A.first-B.first)+llabs(A.second-B.second);
}
bool check(int l,int r){
    if (dist({sx,sy}, vec[l]) + dist(vec[l],vec[r]) <= T)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    gen_points();
    cin>>sx>>sy>>T;
    int ret=0;
    for (int l=0;l<vec.size();l++) {
        for (int r=l;r<vec.size();r++) {
            if (check(l, r) || check(r, l)) ret = max(ret, r - l + 1);
        }
    }
    cout<<ret<<endl;
}