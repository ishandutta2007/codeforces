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
#define INF 100000000
#define MOD 1000000007
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

ll factorial(int x){
    if(x <= 1) return 1;
    return x*factorial(x-1);
}

ll noZeroPerms(vector<int> digits){
    int digCount = 0;
    for(int i=0; i<digits.size(); i++){
        digCount += digits[i];
    }

    ll nonzero = factorial(digCount);
    for(int i=0; i<digits.size(); i++){
        if(digits[i] > 1){
            nonzero /= factorial(digits[i]);
        }
    }
    
    return nonzero;
}

//perms includes making sure 0 doesn't work
ll permutations(vector<int> digits){
    int digCount = 0;
    for(int i=0; i<digits.size(); i++){
        digCount += digits[i];
    }

    //first we do non-zero stuff
    ll nonzero = factorial(digCount);
    for(int i=0; i<digits.size(); i++){
        if(digits[i] > 1){
            nonzero /= factorial(digits[i]);
        }
    }

    if(digits[0]){
        vi copy(digits);
        copy[0]--;
        //cout << "there was a zero, the number of no zeroes is " << noZeroPerms(copy) << "\n";
        return nonzero - noZeroPerms(copy);
    }
    return nonzero;
}

int main(){
    string bus;
    cin >> bus;

    vb busDigs(10, 0);
    for(int i=0; i<bus.length(); i++){
        busDigs[bus[i]-'0'] = true;
    }

    ll totalAmt = 0;
    
    set<vector<int>> possDigs;

    vector<int> currDigs;
    bool bad;
    for(ll i=0; i<(1 << bus.length()); i++){
        bad = false;
        currDigs.assign(10, 0);
        for(int j=0; j<bus.length(); j++){
            if(i & (1 << j)){
                currDigs[bus[j]-'0']++;
                //cout << "digit " << bus[j]-'0' << " shows up!\n";
            }
        }

        for(int j=0; j<10; j++){
            if(busDigs[j] && currDigs[j] == 0){
                bad = true;
                //cout << j << " stops working help\n";
                break;
            }
        }
        if(bad){
            //cout << i << " is bad\n";
            continue;
        }

        if(!possDigs.count(currDigs)){
            possDigs.insert(currDigs);
            //cout << "testing perms of " << i << ", which is " << permutations(currDigs) << "\n";
            totalAmt += permutations(currDigs);
        }
    }

    cout << totalAmt;
    return 0;
}