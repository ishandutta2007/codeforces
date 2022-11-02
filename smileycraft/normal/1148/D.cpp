
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<pair<long long, long long>> input(n);
    vector<long long> inc, dec;
    for (long long i = 0; i < n; ++i){
        cin >> input[i].first >> input[i].second;
        if (input[i].first < input[i].second) inc.push_back(i);
        else dec.push_back(i);
    }
    cout << max(inc.size(), dec.size()) << endl;
    if (inc.size() < dec.size()){
        sort(dec.begin(), dec.end(), [&](long long i, long long j){
             return input[i].second < input[j].second;
        });
        for (long long i = 0; i < dec.size() - 1; ++i) cout << dec[i] + 1 << ' ';
        cout << dec.back() + 1 << endl;
    }
    else{
        sort(inc.begin(), inc.end(), [&](long long i, long long j){
             return input[i].first > input[j].first;
        });
        for (long long i = 0; i < inc.size() - 1; ++i) cout << inc[i] + 1 << ' ';
        cout << inc.back() + 1 << endl;
    }
    return 0;
}