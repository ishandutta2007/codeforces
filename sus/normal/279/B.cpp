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
    int n; cin >> n;
    int t; cin >> t;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    // for(int i=0; i<n; i++){
    //     int temp = 0;
    //     int time = t;
    //     int e = 0;
    //     for(int j=i; j<n; j++){
    //         if(time-arr[j]>=0) 
    //         {
    //             temp++;
    //             e+=arr[j];
    //             //cout << temp << sp << e << ln;
    //             time = time-arr[j];
    //         }
    //         else{
    //             break;
    //         }
        
    //     }
    //     ans = max(ans, temp);
    // }
    //for(int i=0; i<n-2; i++){
        int left = 0;
        int temp = 0;
        int right = 0;
        int time = 0;
        while(right<=n-1){
            //cout << left << sp << right << ln;
            if(time+arr[right]<=t) 
            {
                temp++;
                time = time+arr[right];
                //cout << temp << sp << time << sp << left << sp << right << ln;
                right++;
            }
            else{
                time-=arr[left];
                left++;
                //time = 0;
                //temp = 0;
                temp--;
            }
            ans = max(temp, ans);
            
        }
    
    cout << ans;
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}