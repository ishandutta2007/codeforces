#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
#define endl '\n'
#define ll long long
#define int long long
ll st[200050];
ll w,l,a,sz;
bool check(ll x) {
    if(x>sz) return false;
    if(w%x==0) {
        if((l-1)%x==1) {
            return true;
        }
        if((l-1)%x==0) {
            if(x-1==1) {
                return true;
            }
        }
    }
    if(w%x==1) {
        if(l%x==0) {
            if((l-2)%x==0) return true;
        }
        if(l%x==1) {
            return true;
        }
    }
    if(l%x==0) {
        if((w-1)%x==1) {
            return true;
        }
        if((w-1)%x==0) {
            if(x-1==1) {
                return true;
            }
        }
    }
    if(l%x==1) {
        if(w%x==0) {
            if((w-2)%x==0) return true;
        }
        if(w%x==1) {
            return true;
        }
    }
    return false;
}
void solve() {
    cin>>w>>l;
    int c=0;
    a=2*w+2*l-4;
    sz=min(w,l);
    st[c++]=1;
    for(ll i=2;i*i<=a&&i<=sz;i++) {
        if(a%i==0) {
            if(check(i)) st[c++]=i;
            if(a/i!=i&&check(a/i)) st[c++]=a/i;
        }
    }
    sort(st,st+c);
    cout<<c<<' ';
    for(int i=0;i<c;i++) {
        cout<<st[i]<<" \n"[i==c-1];
    }
}
signed main() {
    IOS;
    int __;
    cin>>__;
    while(__--) solve();
    return 0;
}