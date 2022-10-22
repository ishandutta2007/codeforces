#include <algorithm>
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
    vector<int> prime = enum_prime(100000);
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        int p = *lower_bound(prime.begin(), prime.end(), d + 1);
        int q = *lower_bound(prime.begin(), prime.end(), d + p);
        cout << p * q << endl;
    }
}