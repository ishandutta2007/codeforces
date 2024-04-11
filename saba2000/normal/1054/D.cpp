#include<bits/stdc++.h>
using namespace std;
int a[200009];
int s[200009];
map<int,int> M;
main(){
    long long n, k ;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 0; i <= n; i++){
        if(i) s[i] = (s[i-1]^a[i]);
        int a = min(s[i], (1<<k)-s[i]-1);
        M[a]++;
    }
    long long ans = 0;
    for(auto it = M.begin(); it != M.end(); it++){
        int x = it->second;
        long long a = x/2, b= x-x/2;
        ans += a*(a-1)/2+b*(b-1)/2;
    }
    cout << n*(n+1)/2-ans << endl;
}