#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a % b);
}

long long cnt(long long n, long long a){
    long long c = a, res = 0;
    while(c <= n){
        res += n / c;
        //cout << c << ' ' << res << endl;
        if(c <= (long long)(1e18) / a)c *= a;
        else break;
        //cout << c << ' ' << res << endl;
    }

    return res;
}

int main(){
    long long n, b;
    cin >> n >> b;

    vector<pair<long long, long long> > a;
    for(long long i = 2; i * i <= b; i++)if(b % i == 0){
        a.push_back({i, 0});
        while(b % i == 0){
            a[a.size() - 1].second++;
            b /= i;
        }
    }

    if(b > 1)a.push_back({b, 1});

    long long mn = 1e18;
    for(int i = 0; i < a.size(); i++){
        //cout << a[i].first << ' ' << a[i].second << endl;
        mn = min(mn, cnt(n, a[i].first) / a[i].second);
    }

    cout << mn;
}