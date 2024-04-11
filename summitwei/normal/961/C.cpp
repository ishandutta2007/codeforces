#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007
#define INF 1000000000

int main(){
    int n;
    cin >> n;

    vvvi grids(4);
    for(int i=0; i<4; i++){
        grids[i].resize(n);
        for(int j=0; j<n; j++){
            grids[i][j].resize(n);
            string input;
            cin >> input;
            for(int k=0; k<n; k++){
                grids[i][j][k] = input[k]-'0';
            }
        }
    }

    vi blackCDiff(4); //stores the difference btwn this and a black corner board
    for(int i=0; i<4; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int num = grids[i][j][k];
                int wanted = (j+k+1)%2;
                if(num == wanted){
                    count++;
                }
            }
        }
        blackCDiff[i] = count;
    }

    //now we have the four diffs, so calc greedily how many squares are needed for each.
    sort(blackCDiff.begin(), blackCDiff.end());

    int amtMovements = blackCDiff[0] + blackCDiff[1] + (n*n-blackCDiff[2]) + (n*n-blackCDiff[3]);
    cout << amtMovements;

    return 0;
}