#include<bits/stdc++.h>
using namespace std;
main(){
    int n;
    cin >> n;
    vector<int> v;
    set<long long> S;
    for(int i= 1; i * i <= n; i++){
        if(n % i == 0) {v.push_back(i);
        if(i * i != n) v.push_back(n/i);
        }
    }
    for(int k = 0; k < v.size(); k++){
        long long t = v[k];
        long long d = n / t;
        long long s = (1 + (1 + (d - 1) * t))*d/2;
        S.insert(s);
    }
    for(auto it = S.begin(); it != S.end(); it++){
        cout<<*it<<" ";
    }
}