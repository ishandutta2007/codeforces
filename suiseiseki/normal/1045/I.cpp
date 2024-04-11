#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include <map>
using namespace std;
typedef long long ll;
map<ll,ll> S;
#define MAXN 1000007
ll num[MAXN];
ll n;ll A[26],res;
int main(){
    cin >> n;getchar();
    for(ll i=0;i<n;++i){
        static char ch;
        memset(A,0,sizeof A);
        while(ch = getchar())
            if(ch!='\n')++A[ch-'a'];
            else break;
        for(ll j=0;j<26;++j)
            num[i] |= ((A[j]%2)<<j);
    }
    sort(num,num+n);
    for(ll i=0;i<n;++i){
        res += S[num[i]];
        for(ll j=0;j<26;++j){
        	if((num[i]>>j)&1) res += S[num[i]^(1<<j)];
		}
        ++S[num[i]];
    }
    cout << res<<endl;
    return 0;
}