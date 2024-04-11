#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N=1e3+1;
vector<int> primes,is_prime(MAX_N,1);

int sieve(){
    is_prime[0]=is_prime[1]=0;
    for (int i=2;i<MAX_N;++i){
        if (is_prime[i]){
            primes.emplace_back(i);
            for (int j=2*i;j<MAX_N;j+=i) is_prime[j]=0;
        }
    }
    return primes.size();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n=sieve();
    for (int i=0;i<n;++i){
        for (int j=primes[i];j<MAX_N;j+=primes[i]){
            if (!is_prime[j]) is_prime[j]=primes[i];
        }
    }
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n),ans(n);
        for (int i=0;i<n;++i) cin >> a[i];
        for (int i=0;i<n;++i) ans[i]=is_prime[a[i]];
        vector<int> compress(n),res(n);
        for (int i=0;i<n;++i) compress[i]=ans[i];
        sort(compress.begin(),compress.end());
        compress.erase(unique(compress.begin(),compress.end()),compress.end());
        for (int i=0;i<n;++i) res[i]=lower_bound(compress.begin(),compress.end(),ans[i])-compress.begin()+1;
        cout << compress.size() << '\n';
        for (int i=0;i<n;++i) cout << res[i] << (i!=n-1?' ':'\n');
    }
}