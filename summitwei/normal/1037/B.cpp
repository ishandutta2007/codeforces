#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

int nums[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums, nums+n);

    int mid = nums[n/2];

    ll cnt = 0;
    if(mid < s){
        for(int i=n/2; i<n; i++){
            if(nums[i] >= s) break;
            cnt += 1LL*(s-nums[i]);
        }
    } else if(mid > s){
        for(int i=n/2; i>=0; i--){
            if(nums[i] <= s) break;
            cnt += 1LL*(nums[i]-s);
        }
    }

    cout << cnt << "\n";

    return 0;
}