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
#define MOD 1000000007
#define EPSILON 0.00001

ll mod(int a, int b){
    return ((a % b) + b) % b;
}

int main(){
    int N, M;
    cin >> N >> M;

    vi nums(N+2); //0, N numbers, M
    nums[0] = 0;
    for(int i=0; i<N; i++){
        cin >> nums[i+1];
    }
    nums[N+1] = M;

    int amountOn = 0;
    int amountOff = 0; //when we do something, both of these are switched
    bool thisOneOn = (N % 2 == 0);
    //we loop backwards through the array - at each section, we can find the maximum amount of time gained from swapping there
    int maxAmtGained = 0;
    for(int i=N; i>=0; i--){
        //cout << "on " << i << "\n";
        //interval being checked is from i to i+1.
        if(thisOneOn){
            //lose one, gain off-on
            int amountGainedHere = amountOff-amountOn-1;
            //cout << "amt gained here is " << amountGainedHere << "\n";
            maxAmtGained = max(maxAmtGained, amountGainedHere);
        } else{
            //gain this interval minus one plus blah
            int amountGainedHere = amountOff-amountOn+nums[i+1]-nums[i]-1;
            //cout << "amt gained here is " << amountGainedHere << "\n";
            maxAmtGained = max(maxAmtGained, amountGainedHere);
        }

        if(thisOneOn){
            amountOn += (nums[i+1]-nums[i]);
        } else{
            amountOff += (nums[i+1]-nums[i]);
        }

        thisOneOn = !thisOneOn;
    }

    cout << (maxAmtGained + amountOn) << "\n";

    /*for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }*/
    return 0;
}