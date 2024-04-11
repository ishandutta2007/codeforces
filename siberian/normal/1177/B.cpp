#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define re return
#define ll long long
#define ull unsigned ll
#define ld long double
#define f first
#define s second
#define pi acos(-1)
#define oo (ll)1e9+8
#define OO 1e18
#define EPS 1e-9
#define Endl '\n'
#define all(v) (v).begin(),(v).end()
#define FX(n) fixed<<setprecision(n)
#define mm(o,k) memset(o,k,sizeof o)
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N=5e4+5,M=1e6+5;
ll k,l(1),r(9),sum;
int cnt=1;
int main()
{
    cin >> k;
    while(true){
        if(sum+(r-l+1)*cnt>=k)break;
        sum+=(r-l+1)*cnt;
        ++cnt;
        l*=10;
        r*=10;
        r+=9;
    }
    l+=(k-sum)/cnt;
    sum+=(k-sum)/cnt*cnt;
    if(k==sum)
        cout<<(l-1)%10<<endl;
    else {
        string s=to_string(l);
        cout<<s[k-sum-1]<<endl;
    }
    re 0;
}