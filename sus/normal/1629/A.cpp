#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int k; cin >> k;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        vector< pair <int,int> > vect;
        for (int i=0; i<n; i++){
            vect.push_back( make_pair(a[i],b[i]) );
        }
        sort(vect.begin(), vect.end());
        //cout <<  vect[0].first << ln;
        for(int i=0; i<n; i++){
            if(vect[i].first<=k){
                k+=vect[i].second;
            }
            else {
                break;
            }
        }
        cout << k << ln;
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}