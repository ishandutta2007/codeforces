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

    ll n;
    cin >> n;
    vll nums(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        nums[i] = x-1; //this is so that i can use a 0-based array
    }
    /*for(ll i=0; i<n; i++){
        nums[i] = i;
    }*/

    //store leftmost appearance, store rightmost appearance,
    //then you can binary search for each value after you sort

    vll leftmosts(100000, INF);
    vll rightmosts(100000, -1);
    for(ll i=0; i<n; i++){
        if(leftmosts[nums[i]] == INF){
            leftmosts[nums[i]] = i;
        }
        rightmosts[nums[i]] = i;
    }

    sort(leftmosts.begin(), leftmosts.end());
    sort(rightmosts.begin(), rightmosts.end());

    ll numPairs = 0; //REMINDER TO CHANGE THINGS TO LL WHEN APPLICABLE

    for(ll i=0; i<100000; i++){
        //cout << "processing " << i << "\n";
        if(leftmosts[i] == INF) break;

        auto u = upper_bound(rightmosts.begin(), rightmosts.end(), leftmosts[i]);
        ll diff = rightmosts.end() - u;
        numPairs += diff;
    }

    cout << numPairs << "\n";
    return 0;
}