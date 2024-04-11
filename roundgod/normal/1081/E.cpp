#include<bits/stdc++.h>
#define maxn 200005

using namespace std;
typedef long long ll;
const ll INF=1000000000;
typedef double db;
vector <ll> h[maxn];
ll a[maxn],b[maxn],n;
ll solve(ll x,ll y){
    ll mn=INF;
    for (int i=0;i<h[y].size();i++){
        ll s=h[y][i],t=y/s;
        ll u=(t-s)/2,v=(t+s)/2;
        if (u>x) mn=min(mn,u);
    }
    if (mn==INF) return -1;
    return mn;
}

int main(){
    for (int i=1;i<maxn;i++)
        for (int j=i;(ll)j*i<maxn;j++)
            if ((i+j)%2==0) {
                h[i*j].push_back(i);
                //cout<<i*j<<' '<<i<<endl;
            }
    cin >> n;
    for (int i=2;i<=n;i+=2) cin >> a[i];
    for (int i=2;i<=n;i+=2){
        ll w=solve(b[i-2],a[i]);
        if (w==-1) {puts("No");return 0;}
        b[i-1]=w; b[i]=(ll)sqrt((db)w*w+a[i]+0.5);
    }
    puts("Yes");
    for (int i=1;i<=n;i++) cout << b[i]*b[i]-b[i-1]*b[i-1] << ' '; cout << endl;
}