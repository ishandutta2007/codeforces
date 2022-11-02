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
    int N;
    cin >> N;

    vi nums(4, 0); //stores count of number of appearances of 5-i
    int totalSum = 0;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        totalSum += x;
        nums[5-x]++;
    }

    int scoreNeeded = (N*9+1)/2;
    int morePoints = scoreNeeded - totalSum;

    int changes = 0;
    while(morePoints > 0){
        for(int i=3; i>=0; i--){
            if(nums[i]){
                nums[i]--;
                changes++;
                morePoints -= i;
                break;
            }
        }
    }

    cout << changes;
    return 0;
}