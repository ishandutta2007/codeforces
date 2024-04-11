#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define endl "\n"
const int inf = 1e18;

void print(int a, int b, int c, int d, int e, int f) {
    int n = 4;
    if(a==c||b==d) {
        n--;
    }
    if(c==e||d==f) {
        n--;
    }
    cout << n << endl;
    if(a!=c) {
        cout << a << " " << b << " " << c << " " << b << endl;
    }
    if(b!=d) {
        cout << c << " " << b << " " << c << " " << d << endl;
    }
    if(e!=c) {
        cout << c << " " << d << " " << e << " " << d << endl;
    }
    if(f!=d) {
        cout << e << " " << d << " " << e << " " << f << endl;
    }
}

int mid(int a, int b, int c) {
    vector<int> ded({a,b,c});
    sort(ded.begin(),ded.end());
    return ded[1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);    
    
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    int x = mid(x1,x2,x3);
    int y = mid(y1,y2,y3);
    
    vector<vector<int>> res;    
    
    if(y1!=y) {
        res.pb({x,y1,x,y});
    }
    if(x1!=x) {
        res.pb({x1,y1,x,y1});
    }
    if(y2!=y) {
        res.pb({x,y2,x,y});
    }
    if(x2!=x) {
        res.pb({x2,y2,x,y2});
    }
    if(y3!=y) {
        res.pb({x,y3,x,y});
    }
    if(x3!=x) {
        res.pb({x3,y3,x,y3});
    }
    cout << res.size() << endl;
    for(int i=0;i<res.size();i++) {
        for(int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}