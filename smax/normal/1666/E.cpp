#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

bool pass(int l, int r, vector<int> &loc, int len) {
    // cout << l << " " << r << endl;
    int n = loc.size()-1;
    if(r<loc[0] || l > loc[1]) {
        return false;
    }
    vector<int> lrange(n);
    vector<int> rrange(n);
    lrange[0] = max(loc[0],l);
    rrange[0] = min(loc[1],r);
    for(int x=1;x<n;x++) {
        if(rrange[x-1]+r<loc[x] || lrange[x-1]+l>loc[x+1]) {
            return false;
        }
        lrange[x] = max(lrange[x-1]+l,loc[x]);
        rrange[x] = min(rrange[x-1]+r,loc[x+1]);
    }
    // for(int x=0;x<n;x++) {
    //     cout << lrange[x] << " " << rrange[x] << " blah" << endl;
    // }
    if(lrange[n-1] <= len && len <= rrange[n-1]) {
        return true;
    }
    return false;
}

void recover(int l, int r, vector<int> &loc, int len) {
    int n = loc.size()-1;
    vector<int> lrange(n);
    vector<int> rrange(n);
    lrange[0] = max(loc[0],l);
    rrange[0] = min(loc[1],r);
    for(int x=1;x<n;x++) {
        lrange[x] = max(lrange[x-1]+l,loc[x]);
        rrange[x] = min(rrange[x-1]+r,loc[x+1]);
    }

    vector<int> act(n+1);
    act[0] = 0;
    act[n] = len;
    
    for(int x=n-1;x>0;x--) {
        act[x] = min(act[x+1]-l,rrange[x-1]);
    }
    for(int x=0;x<n;x++) {
        cout << act[x] << " " << act[x+1] << endl;
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int len,n;
    cin >> len >> n;
    vector<int> loc(n+1);
    for(int x=0;x<n;x++) {
        cin >> loc[x];
    }
    loc[n] = 1e18;
        
    if(n==1) {
        cout << "0 " << len << endl;
        return 0;
    }
    
    int sl = 0, sr = 1e9+1;
    int b;
    while(sl+1<sr) {
        int smid = (sl+sr)/2;
        int bl = smid-1, br = 1e9;
        bool possible = false;
        while(bl+1<br) {
            int bmid = (bl+br)/2;
            
            if(pass(smid,bmid,loc,len)) {
                br = bmid;
                possible = true;
            }
            else {
                bl = bmid;
            }
            
        }
        
        if(possible) {
            b = br;
            sl = smid;
        }
        else {
            sr = smid;
        }
    }
    
    // cout << sl << " " << b << endl;
    
    recover(sl,b,loc,len);
    
    return 0;
}