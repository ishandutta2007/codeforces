#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back


ll arr[1010101];
vector <ll> prime;
bool is_composite[1010101];

void sieve (int n) {
    std::fill (is_composite, is_composite + n, false);
    for (int i = 2; i <n; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll i,j,k,l,m,n,x;
    cin>>n;
    if(n==1){
        cout<<"C 1"<<'\n';
        return 0;
    }
    sieve(n+1);
    ll all=n;
    ll fl=prime.size();
    //printf("%lld\n",fl);
    while(1){
        ll era=0;
       for(i=fl/2+1;i<=fl;i++){
            j=prime[i-1];
            cout<<"B "<<j<<'\n';
            cin>>x;
            era+=x;
        }
        cout<<"A 1"<<'\n';
        cin>>k;
        if(k!=all-era){
            ll ans=1;
            ll mini=1e18;
            for(i=fl/2+1;i<=fl;i++){
                j=prime[i-1];
                k=j;
                while(1){
                    cout<<"A "<<k<<'\n';
                    cin>>x;
                    if(x==0) break;
                    ans*=j;
                    k*=j;
                    mini=min(mini,i);

                    if(k>n) break;
                }
            }

            for(i=1;i<mini;i++){
                j=prime[i-1];
                if(ans*j>n) break;
                k=j;
                cout<<"B "<<k<<'\n';
                 cin>>x;
                while(1){
                    cout<<"A "<<k<<'\n';
                    cin>>x;
                    if(x==0) break;
                    ans*=j;
                    k*=j;
                    if(k>n) break;
                }
            }
            cout<<"C "<<ans<<'\n';
            return 0;
        }
        else{
            all=k;
            fl=fl/2;
        }

        if(fl==0){
            cout<<"C 1"<<'\n';
            return 0;
        }
    }
}