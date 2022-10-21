#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 500500;

int n,r;
ll k;
ll a[MAXN];
ll b[MAXN];

bool check(ll t){
//    memcpy(b, a, n*sizeof(int));
    for(int i = 0; i < n; i++) b[i] = a[i];

    ll cursum = 0;
    for(int i = 0; i <= min(r,n-1); i++) cursum += b[i];
    ll rem = k;
    for(int i = 0; i < n; i++){
        if(cursum < t){
            ll dif = t-cursum;
            b[min(i+r,n-1)] += dif;
            cursum += dif;
            rem -= dif;
            if(rem < 0) return false;
        }
        if(i-r >= 0) cursum -= b[i-r];
        if(i+r+1 < n) cursum += b[i+r+1];

    }
    return true;
}

int main(){
    scanf("%d%d", &n, &r);
    cin >> k;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    ll l = -1, r = (ll)5e18 + 5;
    while(l+1 < r){
        ll mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(l == -1) l++;
    cout << l;
}