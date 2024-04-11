#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<int, long long>> vpil;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
typedef vector<vector<set<int>>> vvsi;
typedef vector<vector<set<pair<long long, long long>>>> vvspll;
typedef pair<long long, long long> pll;
typedef pair<long long, pair<long long, long long>> trip;
#define INF 1000000000
#define MOD 998244353
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int n, B;
    cin >> n >> B;

    vi numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    vi validCuts;
    int moreOdds;
    if(numbers[0] % 2 == 0){
        moreOdds = -1;
    } else{
        moreOdds = 1;
    }
    for(int i=1; i<n; i++){
        if(moreOdds == 0 && i != 0){
            int bitcoins = numbers[i]-numbers[i-1];
            if(bitcoins < 0) bitcoins = -bitcoins;
            validCuts.push_back(bitcoins);
        }

        if(numbers[i] % 2 == 0){
            moreOdds--;
        } else{
            moreOdds++;
        }
    }

    sort(validCuts.begin(), validCuts.end());
    int coinsUsedSoFar = 0;
    int totalCuts = 0;
    for(int i=0; i<validCuts.size(); i++){
        if(coinsUsedSoFar + validCuts[i] <= B){
            coinsUsedSoFar += validCuts[i];
            totalCuts++;
        } else{
            break;
        }
    }
    
    cout << totalCuts;
    return 0;
}