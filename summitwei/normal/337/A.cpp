#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, n;
    cin >> a >> n;
    vector<int> prices;

    prices.resize(n);

    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end());

    int minDif = prices[n-1] - prices[0];

    for(int j=0; j<n-a+1; j++){
        int newDif = prices[j+a-1] - prices[j];

        if(newDif < minDif){
            minDif = newDif;
        }
    }

    cout << minDif;
    return 0;
}