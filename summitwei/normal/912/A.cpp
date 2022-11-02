#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    long long A, B, X, Y, Z;
    cin >> A >> B;
    cin >> X >> Y >> Z;

    ll redNeeded = 2 * X + Y;
    ll blueNeeded = 3 * Z + Y;

    ll totalSum = 0;

    if(redNeeded > A){
        totalSum += (redNeeded - A);
    }
    if(blueNeeded > B){
        totalSum += (blueNeeded - B);
    }


    cout << totalSum;

    return 0;
}