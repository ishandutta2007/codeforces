#include<bits/stdc++.h>
using namespace std;
int s[209],f[209];
int a[209], b[209];
int n, k;
int sg(int x, int a, int b){
    if(x < a) x += 2*n;
    if(b < a) b += 2*n;
    return a < x && x < b;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >>a[i]>>b[i];
            f[a[i]] = 1;
            f[b[i]] = 1;
        }
        int ans = (n-k)*(n-k - 1)/2;
        for(int i = 1; i <= k; i++){
            for(int j = i+1; j <= k; j++){
                if(sg(a[j], a[i], b[i]) != sg(b[j], a[i], b[i]))
                    ans++;
            }
            int N = 0;
            for(int j = 1; j <= 2*n; j++){
                if(f[j] == 0 && sg(j, a[i], b[i])) N++;
            }
            N = min(N, 2*(n-k) - N);
            ans += N;
        }
        for(int i = 1; i <= 2*n; i++)
            f[i] = 0;
        cout<<ans<<endl;


    }

}