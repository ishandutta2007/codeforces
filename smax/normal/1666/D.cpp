#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int t;
    cin >> t;
    while(t--) {
        string a,b;
        cin >> a >> b;
        int curr = b.size()-1;
        set<char> ded;
        for(int x = a.size()-1;x>=0;x--) {
            if(!ded.count(a[x]) && a[x]==b[curr]) {
                curr--;
                if(curr==-1) {
                    break;
                }
            }
            else {
                ded.insert(a[x]);
            }
        }
        if(curr==-1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
        
        
        
    }
    
    return 0;
}