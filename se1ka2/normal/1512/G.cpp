#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int M = 10000000;

std::vector<int> enum_prime(int n){     // containing n
    std::vector<int> res;
    if (n <= 1) return res;
    std::vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

ll d[M + 5];
ll r[M + 5];

int main()
{
    for(int i = 1; i <= M; i++) d[i] = 1;
    vector<int> prime = enum_prime(M);
    for(int p : prime){
        ll x = p;
        ll s = 1;
        while(x <= M){
            s += x;
            for(int i = x; i <= M; i += x){
                if(i % (x * p) == 0) continue;
                d[i] *= s;
            }
            x *= p;
        }
    }
    for(int i = 1; i <= M; i++) r[i] = -1;
    for(int i = 1; i <= M; i++){
        if(d[i] > M) continue;
        if(r[d[i]] == -1) r[d[i]] = i;
    }
    int t;
    cin >> t;
    while(t--){
        int c;
        cin >> c;
        cout << r[c] << endl;
    }
}