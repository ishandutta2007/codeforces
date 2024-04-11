#include<bits/stdc++.h>
using namespace std;
long long f[500009];
long long a[500009];
long long s[500009];
main(){
    long long n;
    cin >> n;
    long long S = 0;
    long long ll = 0, rr = n;
    for(long long i = 1; i <= n; i++){
        int T;
        scanf("%d", &T);
        a[i] = T;
        S ^= a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for(long long i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    s[n + 1] = s[n];
    long long j = n + 1;
    for(long long k = 1; k <= n; k++){
        while(j > 1 && a[j - 1] <= k) j--;
        long long C = n - max(j - 1, k);
        long long B = max(0ll, j -  1 - k);
        long long A = k;
        long long T = k * (k - 1) - s[k] + B * k + s[n] - s[max(j - 1, k)];
        if(T + A < 0){
            cout<<-1<<endl;
            return 0;
        }
        
        long long L = max(0ll, -T);
        long long R = min(n, A + B + T + A );
        //cout<<L<<" "<<R<<endl;
        ll = max(ll, L);
        rr = min (rr, R);
    }
    long long ans = 0;
    for(long long i = ll; i <= rr; i++){
        if((i ^ S) % 2 == 0){
            printf("%d ", (int)i);
            ans++;
        }
    }
    if(!ans) cout<<-1<<endl;
    
}