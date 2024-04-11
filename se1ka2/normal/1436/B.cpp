#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    int t;
    cin >> t;
    vector<int> prime = enum_prime(100000);
    bool p[100005]{0};
    for(int i : prime) p[i] = true;
    while(t--){
        int n;
        cin >> n;
        for(int i = n - 1; i < 100000; i++){
            if(p[i] && !p[i - n + 1]){
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        if(j == k) cout << i - n + 1 << " ";
                        else cout << 1 << " ";
                    }
                    cout << endl;
                }
                break;
            }
        }
    }
}