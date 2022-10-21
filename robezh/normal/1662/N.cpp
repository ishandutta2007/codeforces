#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
const int N = 2e3;
int a[N][N];
int col[N][N], row[N][N]; //Number of elm lower than it

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++) {
        pii temp[n];
        for(int j=0;j<n;j++)
            temp[j] = {a[i][j],j};
        sort(temp,temp+n);
        for(int j=0;j<n;j++) {
            row[i][temp[j].second] = j;
        }
        for(int j=0;j<n;j++)
            temp[j] = {a[j][i],j};
        sort(temp,temp+n);
        for(int j=0;j<n;j++) {
            col[temp[j].second][i] = j;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ll add = 0;
            add += 1LL*(col[i][j])*(n-1-row[i][j]);
            add += 1LL*(row[i][j])*(n-1-col[i][j]);
//            cout<<i<<' '<<j<<' '<<col[i][j]<<' '<<row[i][j]<<' '<<a[i][j]<<' '<<add<<endl;
            ans += add;
        }
    }
    cout<<ans/2;

    return 0;
}

//3
//9 2 4
//1 5 3
//7 8 6
//0 0 2 2 9 0
//0 1 0 0 2 0
//0 2 1 1 4 2
//1 0 0 0 1 0
//1 1 1 2 5 2
//1 2 2 1 3 2
//2 0 1 1 7 2
//2 1 0 2 8 4
//2 2 2 0 6 4
//8