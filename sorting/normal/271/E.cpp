#include <bits/stdc++.h>

using namespace std;

const int N = 100007;

long long a[N];
long long n, m;

long long solve(long long d){
    long long res = 0;

    for(; d < m; d *= 2){
        res += m - d;
    }   
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;  
    }
    
    long long gcd = a[0];
    
    for(int i = 1; i < n; i++){
        gcd = __gcd(a[i], gcd);   
    }
    
    long long res = 0;
    
    while(gcd % 2 == 0){
        gcd /= 2;
    }
    
    for(int i = 1; i*i <= gcd; i+=2){
        if(gcd % i == 0){
            res += solve(i);
            
            if(i *i != gcd){
                res += solve(gcd / i);
            }
        }
    }
    
    cout << res << "\n";
    
    return 0;
}