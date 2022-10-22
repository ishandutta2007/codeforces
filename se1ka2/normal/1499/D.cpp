#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct PrimeDecomposition
{
    int n;
    vector<bool> p;
    vector<int> prime;
    vector<int> d;
    
    PrimeDecomposition(int n) : n(n){
        p.resize(n + 1);
        d.resize(n + 1);
        d[1] = 1;
        for(int i = 2; i <= n; i++){
            if(!p[i]){
                prime.push_back(i);
                for(int j = i; j <= n; j += i){
                    if(!p[j]) d[j] = i;
                    p[j] = true;
                }
            }
        }
    }
    
    int decomposition(int x){
        int res = 0, last = 0;
        while(x > 1){
            if(last != d[x]){
                last = d[x];
                res++;
            }
            x /= d[x];
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    PrimeDecomposition pd(20000000);
    while(t--){
        int c, d, x;
        cin >> c >> d >> x;
        vector<int> v;
        for(int i = 1; i * i <= x; i++){
            if(x % i) continue;
            v.push_back(i);
            if(i * i != x) v.push_back(x / i);
        }
        ll ans = 0;
        ll p[50];
        p[0] = 1;
        for(int i = 1; i <= 40; i++) p[i] = p[i - 1] * 2;
        for(int i : v){
            if((d + i) % c) continue;
            int k = (d + i) / c;
            ans += p[pd.decomposition(k)];
        }
        cout << ans << endl;
    }
}