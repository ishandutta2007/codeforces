//  sathu
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve(){
    string calc; cin >> calc;
    char nums[(calc.size()/2)+1];
    int count = 0;
    for(int i=0; i<calc.size(); i+=2){
        nums[count] = calc[i];
        count++;
    }
    sort(nums, nums+sizeof(nums));
    for(int i=0; i<sizeof(nums)-1; i++){
        cout << nums[i];
        cout << "+";
    }
    cout << nums[sizeof(nums)-1];
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}