#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<vector<int>>>> vvvvi;
typedef vector<vector<long long>> vvll;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef long long ll;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<bool>> vvb;
typedef set<int> si;
#define INF 100000000
#define MOD 257

int mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    string s;
    cin >> s;

    bool allSame = true;
    bool isPali = true;
    for(int i=0; i<s.length(); i++){
        if(s[0] != s[i]){
            allSame = false;
        }
        if(s[i] != s[s.length()-1-i]){
            isPali = false;
        }
    }

    if(allSame){
        cout << 0;
    } else if(isPali){
        cout << s.length()-1;
    } else{
        cout << s.length();
    }

    return 0;
}