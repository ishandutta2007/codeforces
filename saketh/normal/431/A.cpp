#include<iostream>
#include<vector>
using namespace std;

int cost[4];
string lets;

int main(){
    cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
    cin >> lets;
    
    int ans = 0;
    for(int i=0; i<lets.length(); i++)
        ans += cost[ lets[i] - '1' ];
    cout << ans << endl;
    
    return 0;
}