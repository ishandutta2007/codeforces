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
#define INF 100000000
#define MOD 257

int mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int n, m;
    cin >> n >> m;

    vi seq(n);
    for(int i=0; i<n; i++){
        cin >> seq[i];
    }

    vb printed(10);
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        printed[x] = true;
    }

    string output = "";
    for(int i=0; i<n; i++){
        if(printed[seq[i]]){
            output = output + to_string(seq[i]) + " ";
        }
    }

    cout << output.substr(0, output.length()-1);

    return 0;
}