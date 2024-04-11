#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005

int n;
ll spds[MAX_N][2];
ll vals[MAX_N];
ll val2[MAX_N];
ll sums[MAX_N];

int main(){
    cin >> n;
    
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> spds[j][i];
        }
    }

    
    ll currScore = 0;
    for(int i=0; i<n; i++){
        ll amtNew;
        if(i % 2 == 0){
            amtNew = spds[i][0]*(2*i) + spds[i][1]*(2*i+1);
        } else{
            amtNew = spds[i][1]*(2*i) + spds[i][0]*(2*i+1);
        }

        currScore += amtNew;
        vals[i] = currScore;
    }

    ll currSum = 0;
    for(int i=n-1; i>=0; i--){
        currSum += spds[i][0] + spds[i][1];
        sums[i] = currSum;
    }

    if((n-1) % 2 == 0){
        val2[n-1] = spds[n-1][1];
    } else{
        val2[n-1] = spds[n-1][0];
    }
    int numOn = 2;
    for(int i=n-2; i>=0; i--){
        ll temp = sums[i+1]*(numOn) - val2[i+1];
        if(i % 2 == 0){
            temp += (numOn+1)*spds[i][1];
        } else{
            temp += (numOn+1)*spds[i][0];
        }

        val2[i] = temp;
        numOn += 2;
    }

    ll maxSum = val2[0];
    for(int i=0; i<n; i++){
        ll sumHere = vals[i] + val2[i+1] + sums[i+1]*2*(i+1);
        //cout << "sum at " << i << " is " << sumHere << "\n";
        //cout << "val is " << vals[i] << ", val2 is " << val2[i+1] << " and sum is " << sums[i+1];
        maxSum = max(maxSum, sumHere);
    }

    cout << maxSum << "\n";


    /*for(int i=0; i<n; i++){
        cout << vals[i] << " " << sums[i] << " " << val2[i] << "\n";
    }*/

    return 0;
}