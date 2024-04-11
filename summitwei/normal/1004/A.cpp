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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vi locs(n);
    for(int i=0; i<n; i++){
        cin >> locs[i];
    }

    int ans = 2;

    for(int i=1; i<n; i++){
        int left = locs[i-1];
        int right = locs[i];
        int dist = right - left;
        if(dist == d*2){
            ans += 1;
        } else if(dist > d*2){
            ans += 2;
        }
    }

    cout << ans;
    
    return 0;
}