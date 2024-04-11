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

int main(){
    ll N;
    cin >> N;

    //answer obviously has to be less than N/2, let's just binary search

    bool works = false;
    ll lower = 0;
    ll upper = (N+1)/2;
    ll mid = (lower + upper)/2;
    while(!works){
        if(lower == (upper-1)){
            cout << upper;
            return 0;
        }

        mid = (lower + upper)/2;
        //cout << "testing " << mid << "\n";

        ll vEats = 0;
        ll currAmt = N;
        while(currAmt > 0 && vEats < (N+1)/2){
            if(currAmt <= mid){
                vEats += currAmt;
                currAmt = 0;
                break;
            } else{
                currAmt -= mid;
                vEats += mid;
            }

            currAmt -= (currAmt/10);
            //cout << "current amount is " << currAmt << " and v ate " << vEats << "\n";
        }


        if(vEats >= (N+1)/2){
            upper = mid;
        } else{
            lower = mid;
        }
        //cout << "v ate " << vEats << "\n";
    }

    cout << mid;
    return 0;
}