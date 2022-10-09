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
 
int dig(int x) {
    int c=0;
    while(x) 
    x/=10,c++;
    return c;
}
 
void solve(){
    int t; cin >> t;
    while(t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        int t1 = dig(a) + b;
        int t2 = dig(c) + d;
        
        if(t1> t2) {
            cout<<">";
        }
        else if(t2>t1) {
            cout<<"<";
        }
        else {
            b=c;
            while(dig(a)<dig(b))a*=10;
            while(dig(b)<dig(a))b*=10;
            if(a>b)cout<<">";
            else if(a<b)cout<<"<";
            else cout<<"=";
        }
        cout << ln;
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}