//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
int ans[Maxn];
int main(){
    int n;
    cin >> n;
    if(n == 2){
        cout << 1 << "\n" << 1 << "\n";
        return 0;
    }
    if(n == 3){
        cout << 2 << "\n" << 1 << ' ' << 3 << "\n";
        return 0;
    }
    cout << n << endl;
    int cur = n/2 + n % 2;
    For(i,0,n/2 + n % 2)
        ans[i * 2] = cur--;
    cur = n;
    For(i,0,n/2)
        ans[i * 2 + 1] = cur--;
    For(i,0,n)
        cout << ans[i] << ' ';
    return 0;
    
}