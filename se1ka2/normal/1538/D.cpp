#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    int t;
    cin >> t;
    vector<int> prime = enum_prime(50000);
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        if(a > b) swap(a, b);
        int c = a, e = b;
        int d = 0;
        for(int p : prime){
            while(a % p == 0){
                a /= p;
                d++;
            }
            while(b % p == 0){
                b /= p;
                d++;
            }
        }
        if(a > 1) d++;
        if(b > 1) d++;
        if(k == 1){
            if(c != e && e % c == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(d >= k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}