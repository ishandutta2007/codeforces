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
    //what we really care about is the number of times you need to replace symbols. if we do it once, how much? twice, etc.
    //if we have x batches of 0's, each of which is separated by some ones,
    //1 replace needs x-1 swaps, 2 replace needs x-2 swaps, etc. if you can replace x times you need no swaps.
    //since this is linear we can just check 1 replace and x replaces.
    int n;
    ll x, y;
    cin >> n >> x >> y;

    string input;
    cin >> input;


    int zeroGroups = 0;
    bool currOnZero = false;
    for(int i=0; i<n; i++){
        if(currOnZero && input[i] == '1'){
            currOnZero = false;
        } else if(!currOnZero && input[i] == '0'){
            zeroGroups++;
            currOnZero = true;
        }
    }

    //cout << zeroGroups << "\n";

    if(zeroGroups == 0){
        cout << 0;
    } else{
        cout << min(y+(zeroGroups-1)*x, zeroGroups*y);
    }

    return 0;
}