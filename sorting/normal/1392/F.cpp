#include <bits/stdc++.h>

using namespace std;

const long long k_H = 1e12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long sum = 0;
    vector<long long> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
        sum += h[i];
    }

    long long l = 0, r = k_H;
    while(l != r){
        long long mid = (l + r) >> 1;
        if(mid * n + n * (n - 1) / 2 >= sum) r = mid;
        else l = mid + 1;
    } 

    h[0] = l;
    sum -= h[0];
    bool pr = false;
    for(int i = 1; i < n; ++i){
        if(pr){
            h[i] = h[i - 1] + 1;
            sum -= h[i];
            pr = false;
            continue;
        }
        if(h[i - 1] * (n - i) + (n - i - 1) * (n - i) / 2 >= sum){
            h[i] = h[i - 1];
            sum -= h[i];
            pr = true;
        }
        else{
            h[i] = h[i - 1] + 1;
            sum -= h[i];
            pr = false;
        }
    }

    for(int i = 0; i < n; ++i)
        cout << h[i] << " ";
    cout << "\n";
}