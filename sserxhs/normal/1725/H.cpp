#include<bits/stdc++.h>

using namespace std;

#define N 120000

int n,a[N],cnt[2];

int S(int x){
    int r=0;
    while (x){r+=x%10; x/=10;}
    r%=3;
    return r*r%3;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        a[i]=S(x);
        ++cnt[S(x)];
    }
    int ans=cnt[1]<=cnt[0];
    int sum=n/2-cnt[ans];
    cout<<(ans*2)<<'\n';
    for (int i=1;i<=n;++i){
        if (a[i]==ans) cout<<a[i];
        else{
            if (sum){--sum; cout<<(a[i]^1);}
            else cout<<a[i];
        }
    }
    cout<<'\n';

    return 0;
}