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
    int n;
    cin >> n;
    int totalSum = 0;
    vi balloons(n);
    for(int i=0; i<n; i++){
        cin >> balloons[i];
        totalSum += balloons[i];
    }

    if(n == 1){
        cout << -1;
        return 0;
    }
    if(n == 2 && balloons[0] == balloons[1]){
        cout << -1;
        return 0;
    }

    if(balloons[0]*2 == totalSum){
        cout << "1\n2";
    } else{
        cout << "1\n1";
    }
    return 0;
}