#include <iostream>
#include <vector>
#include <map>
using namespace std;

int gcd(int n, int m){
    if(m == 0) return n;
    return gcd(m, n % m);
}

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
    
    vector<int> decomposition(int x){
        vector<int> res;
        while(x > 1){
            res.push_back(d[x]);
            x /= d[x];
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    PrimeDecomposition pd(1000000);
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int g = 0;
        for(int i = 0; i < n; i++) g = gcd(g, a[i]);
        for(int i = 0; i < n; i++) a[i] /= g;
        map<int, int> d, last;
        int ans = 0;
        for(int i = 0; i < n * 2; i++){
            vector<int> prime = pd.decomposition(a[i % n]);
            for(int p : prime){
                if(last[p] == i - 1) d[p]++;
                else if(last[p] < i - 1) d[p] = 1;
                last[p] = i;
                ans = max(ans, d[p]);
            }
        }
        cout << ans << endl;
    }
}