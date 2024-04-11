#include <bits/stdc++.h>

using namespace std;

int round(int n, int m){
    return int(100 * (long double)(m) / n + 0.5);
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int m = 0;
    vector<pair<int, int> > b(k);
    for(int i = 0; i < k; i++)b[i] = {i, 1};
    vector<bool> is(n, false);
    vector<bool> used(k, false);
    int ind = k;
    while(m < n){
        int q = round(n, m);

        for(int i = 0; i < k; i++)if(!used[i]){

            if(b[i].second == q){
                is[b[i].first] = true;
            }

            b[i].second++;
            if(b[i].second > a[b[i].first]){
                m++;
                if(ind < n){
                    b[i].first = ind;
                    b[i].second = 1;
                    ind++;
                }
                else {
                    //b[i].second = 1000;
                    used[i] = true;
                }
            }

        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)ans += is[i];

    cout << ans;
}