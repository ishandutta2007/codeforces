#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int x,y; cin >> x >> y;
        vector<vector<int>> range(2,vector<int>(2));
        for (int i=0;i<2;++i)
            for (int j=0;j<2;++j)
                cin >> range[i][j];
        int A=x-range[0][0],B=range[1][0]-x,C=y-range[0][1],D=range[1][1]-y;
        int ok=1;
        if (a<b&&B<b-a) ok=0;
        if (b<=a&&A<a-b) ok=0;
        if (c<d&&D<d-c) ok=0;
        if (d<=c&&C<c-d) ok=0;
        if (A+B==0&&0<a+b) ok=0;
        if (C+D==0&&0<c+d) ok=0;
        cout << (ok?"YES":"NO") << '\n';
    }
}