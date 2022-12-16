// Never let them see you bleed...
// Shayan.P  2020-06-30

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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	string s;
	cin >> n >> s;
	int cnt1 = 0, cnt2 = 0;
	for(char ch : s){
	    if(ch == '1')
		break;
	    cnt1++;
	}
	reverse(s.begin(), s.end());
	for(char ch : s){
	    if(ch == '0')
		break;
	    cnt2++;
	}
	reverse(s.begin(), s.end());
	int C1 = 0, C2 = 0;
	for(int i = cnt1; i < sz(s) - cnt2; i++){
	    if(s[i] == '0')
		C1++;
	    else
		C2++;
	}
	string ans;
	if(C1 == 0 || C2 == 0){
	    ans = s;
	}
	else{
	    for(int i = 0; i < cnt1; i++)
		ans+= '0';
	    ans+= '0';
	    for(int i = 0; i < cnt2; i++)
		ans+= '1';
	}
	cout << ans << "\n";
    }
    return 0;
}