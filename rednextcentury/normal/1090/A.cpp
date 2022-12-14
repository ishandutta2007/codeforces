#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MX = (1<<20);

int arr[MX] ;

string str;

ll mx = 0 , cnt[MX] , best[MX];

long long sum[MX];

int n;

int main(){
    cin>>n;
    for(int j = 1 ; j <= n ; j++){
        scanf("%lld",&cnt[j]);
        for(int i = 0 ; i < cnt[j] ; i++){
            int x;
            scanf("%d",&x);
            best[j] = max(best[j] , 1ll * x);
            mx = max(mx , 1ll * x);
            sum[j] += x;
        }
    }

    ll ans = 0;

    for(int j = 1 ; j <= n ; j++){
        ans += cnt[j] * (mx - best[j]);
    }
    cout<<ans<<endl;


}