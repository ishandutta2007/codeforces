#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll k;
    cin >> k;
    ll p[10];
    for(int i = 0; i < 10; i++) p[i] = 1;
    ll s = 1;
    int c = 0;
    while(s < k){
        s = s / p[c] * (p[c] + 1);
        p[c]++;
        c = (c + 1) % 10;
    }
    string cdf = "codeforces";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < p[i]; j++) cout << cdf[i];
    }
    cout << endl;
}