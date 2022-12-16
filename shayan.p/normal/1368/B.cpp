// Never let them see you bleed...
// Shayan.P  2020-06-18

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e5 + 10, mod = 1e9 + 7, inf = 1e9 + 10;


int cnt[10];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    ll n;
    cin >> n;
    for(int i = 0; i < 10; i++)
	cnt[i] = 1;
    ll num = 1;
    int pt = 0;
    while(num < n){
	num/= cnt[pt];
	cnt[pt]++;
	num*= cnt[pt];
	pt = (pt + 1) % 10;
    }
    string s = "codeforces";
    for(int i = 0; i < 10; i++){
	for(int j = 0; j < cnt[i]; j++)
	    cout << s[i];
    }
    return cout << endl, 0;
}