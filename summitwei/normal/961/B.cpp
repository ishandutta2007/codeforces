#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007
#define INF 1000000000

int main(){
    int n, k;
    cin >> n >> k;
    
    vi amtTheo(n);
    vi asleep(n);

    for(int i=0; i<n; i++){
        cin >> amtTheo[i];
    }
    for(int i=0; i<n; i++){
        cin >> asleep[i];
    }

    vi amtGained(n-k+1);
    for(int i=0; i<k; i++){
        amtGained[0] += amtTheo[i];
    }
    for(int i=k; i<n; i++){
        amtGained[0] += (asleep[i])*amtTheo[i];
    }

    for(int i=1; i<n-k+1; i++){
        int lost = (1-asleep[i-1])*amtTheo[i-1];
        int gained = (1-asleep[i+k-1])*amtTheo[i+k-1];
        amtGained[i] = amtGained[i-1]+gained-lost;
    }


    int amtMin = 0;
    for(int i=0; i<n-k+1; i++){
        amtMin = max(amtMin, amtGained[i]);
        //cout << amtGained[i] << " ";
    }
    cout << amtMin;

    return 0;
}