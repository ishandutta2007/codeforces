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
    int n;
    cin >> n;
    vector<int> prime = enum_prime(10000);
    int a[500005];
    int ans[2][500002];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        int b = a[i];
        for(int p : prime){
            if(b % p == 0){
                while(b % p == 0) b /= p;
                break;
            }
        }
        if(b == a[i] || b == 1){
            ans[0][i] = -1;
            ans[1][i] = -1;
        }
        else{
            ans[0][i] = b;
            ans[1][i] = a[i] / b;
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", ans[0][i]);
    cout << endl;
    for(int i = 0; i < n; i++) printf("%d ", ans[1][i]);
    cout << endl;
}