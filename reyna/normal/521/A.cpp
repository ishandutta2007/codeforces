//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%I64d",&a)
#define Put(a) printf("%I64d\n",a)
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;
const int Mod = 1e9 + 7;
int arr[4];
int main(){
    int x = 0;
    int n;
    cin >> n;
    string S;
    cin >> S;
    int Max = 0;
    For(i,0,n){
        if(S[i] == 'A')
            arr[0]++;
        if(S[i] == 'G')
            arr[1]++;
        if(S[i] == 'T')
            arr[2]++;
        if(S[i] == 'C')
            arr[3]++;
        For(j,0,4)
            Max = max(Max,arr[j]);
    }
    For(i,0,4)
        if(arr[i] == Max)
            x++;
    ll ans = 1;
    For(i,0,n)
        ans *= x,ans %= Mod;
    cout << ans << endl;
    return 0;
}