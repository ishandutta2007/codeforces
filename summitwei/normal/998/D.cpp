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
#define MAXNUM 100000000000

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    //wait can't we just do some math and then account for overcounting? eg, some amount of fives and fifties *should*
    //be equal to the same amount of just tens.
    //this math is probably too difficult tbh :/ but like o(n) is already probably too slow so wtf? i think
    //doing math is the only way this can be done.
    //as long as we don't allow more than 9 5's or 10's we actually have a unique creation. so we can just calculate those
    //possibilities and add up everything together?

    ll n;
    cin >> n;
    
    ll totalAmount = 0;
    for(ll i=0; i<9; i++){
        for(ll j=0; j<9; j++){
            if(i+j>n) continue;
            if(i >= 1 && j >= 5) continue;
            ll amtLeft = n - (i+j);
            totalAmount += (amtLeft+1);
            //cout << i << " " << j << " has " << amtLeft+1 << " cases\n";
        }
    }

    cout << totalAmount << "\n";

    /*int n;
    cin >> n;
    __int128 ree = 0+n;
    
    //cout << ree*ree << "\n";
    __int128 blah = ree*ree;
    string output = "";
    while(blah != 0){
        output += (char)('0'+ (blah % 10));
        blah /= 10;
    }

    string reversed = "";
    for(int i=0; i<output.length(); i++){
        reversed += output[output.length()-1-i];
    }

    cout << reversed;*/

    return 0;
}