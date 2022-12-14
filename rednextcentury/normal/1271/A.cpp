#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dist(ll x1,ll y1, ll x2, ll y2){
    return abs(x1-x2)+abs(y1-y2);
}
int n;
ll X[1000000];
ll Y[1000000];
ll sx,sy;
ll ret=0;
ll bX,bY;
ll Try(ll x,ll y){
    if (x<0 || y<0 || x>1e9 || y>1e9)return -1;
    ll cur=0;
    for (int i=0;i<n;i++) {
        if (dist(sx,sy,x,y)+dist(x,y,X[i],Y[i])==dist(sx,sy,X[i],Y[i]))cur++;
    }
    if (cur>=ret){
        ret=cur;
        bX=x,bY=y;
    }
    return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll ret=0;
    for (int i=0;i<=min(d,a);i++) {
        ll remA = a - i;
        ll remD = d - i;
        ll numB = min(b, min(c,remD));
        ret=max(ret,i*e + numB*f);
    }
    cout<<ret<<endl;
}