#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int INF = 100000000;

vector<int> enum_prime(int n){   // containing n
    vector<int> res;
    if (n <= 1) return res;
    vector<bool> p(n + 1);
    fill(p.begin() + 2, p.end(), true);
    for(int i = 2; i <= n; i++){
        if(p[i]){
            res.push_back(i);
            for(int j = i * 2; j <= n; j += i) p[j] = false;
        }
    }
    return res;
}

ll a[100005];
ll d[505][2];
int c[200005];

int main()
{
    int n;
    cin >> n;
    vector<int> prime = enum_prime(200000);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 500; i++) d[i][0] = d[i][1] = INF;
    for(int i = 0; i < n; i++){
        for(int p : prime){
            if(p >= 500) break;
            int s = 0;
            while(a[i] % p == 0){
                a[i] /= p;
                s++;
            }
            if(d[p][0] > s){
                d[p][1] = d[p][0];
                d[p][0] = s;
            }
            else if(d[p][1] > s){
                d[p][1] = s;
            }
        }
        c[a[i]]++;
    }
    ll ans = 1;
    for(int p : prime){
        if(p < 500){
            for(int i = 0; i < d[p][1]; i++) ans *= p;
        }
        else if(c[p] >= n - 1) ans *= p;
    }
    cout << ans << endl;
}