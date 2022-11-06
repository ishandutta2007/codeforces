#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

vector < pair <string,int> > moves, ans;
#define ff first
#define ss second

int n,m,k;

void gon(string s, int x)
{
    if(!x) return;
    moves.push_back(make_pair(s,x));
}

void solve()
{
    for(int i=1; i<n; i++) {
        if(i&1) gon("DUR", m-1);
        else gon("DUL", m-1);

        gon("D", 1);
    }

    if(n&1) gon("R", m-1);
    else gon("L", m-1);

    for(int i=n; i; i--) {
        if(i&1) gon("L", m-1);
        else gon("R", m-1);

        if(i>1) gon("U", 1);
    }
}

void cut()
{
    int j=0;
    for(auto p : moves) {
        int len=p.ff.size(), r=len*p.ss;
        if(r+j>=k) {
            int m=k-j;
            if(m/len) ans.push_back({p.ff, m/len});
            if(m%len) ans.push_back({p.ff.substr(0, m%len), 1});
            break;
        }
        j+=r;
        ans.push_back(p);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    int tot=4*n*m-2*n-2*m;

    if(tot<k) {
        cout << "NO" << endl;
        exit(0);
    }

    cout << "YES" << endl;;

    if(n==1) {
        gon("R", m-1);
        gon("L", m-1);
    }
    else {
        solve();
    }

    cut();

    cout << ans.size() << endl;
    for(auto p : ans) cout << p.ss << " " << p.ff << endl;
}