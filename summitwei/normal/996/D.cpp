#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
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
#define MOD 1000000007
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    //some level of greedy dp definitely works. i think it's fast enough?
    //actually i think you can just greedy this problem LOL

    int n;
    cin >> n;
    vi peoples(2*n);
    for(int i=0; i<2*n; i++){
        cin >> peoples[i];
    }

    int numSteps = 0;
    for(int i=0; i<n; i++){
        int first = peoples[0];
        int other;
        for(int j=1; j<peoples.size(); j++){
            if(peoples[j] == first){
                other = j;
                break;
            }
        }
        numSteps += (other-1);

        peoples.erase(peoples.begin()+other);
        peoples.erase(peoples.begin());
    }

    cout << numSteps << "\n";
    return 0;
}