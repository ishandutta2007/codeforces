#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000009];
long long s[1000009];
long long check(long long p){
    long long ans  = 0;
    for(int i = 1; i < n; i++){
        long long a = s[i];
        ans += min(a % p, p - a % p);
    }
    return ans;
}
/*

*/
main(){
    cin >> n;
    long long S = 0;
    for(int i = 1; i <= n; i++){
        int t;
        scanf("%d", &t);
        a[i] = t;
        S+=a[i];
        s[i] = s[i-1] + a[i];
    }
    if(S == 1){
        cout<<-1<<endl;
        return 0;
    }
    long long ans = 1e18;
    for(long long i = 2; i * i <= S; i++){
        if(S % i == 0){
            ans = min(ans, check(i));
            while(S % i == 0)
                S /= i;
        }
    }
    if(S > 1) ans = min(ans, check(S));
    cout<<ans<<endl;

}