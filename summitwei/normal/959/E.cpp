#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007

int main(){
    ll n;
    cin >> n;

    ll totalAmt = 0;
    ll currChecking = 1; //this represents the difference between two numbers we are comparing.
    while(currChecking < n){
        ll uses = (n-1) / (currChecking);
        if(uses % 2 == 1){
            uses = (uses+1)/2;
        } else{
            uses /= 2;
        }
        totalAmt += uses * currChecking;
        currChecking *= 2;
    }

    cout << totalAmt;

    return 0;
}