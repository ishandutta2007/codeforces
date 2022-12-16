// Never let them see you bleed...
// Shayan.P  2020-06-25

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

string mp[10][200];

string REV(string s){
    reverse(s.begin(), s.end());
    return s;
}
void f(int i, int num, string s){
    if(num > 160)
	return;
    while(sz(s) > 1 && s.back() == '0')
	s.pop_back();
    if(mp[i][num] == "")
	mp[i][num] = s;
    else if(sz(mp[i][num]) < sz(s))
	return;
    else if(sz(mp[i][num]) > sz(s))
	mp[i][num] = s;
    else if(REV(mp[i][num]) > REV(s))
	mp[i][num] = s;
}

void add(string s){
    while(sz(s) > 1 && s.back() == '0')
	s.pop_back();
    string start = s;
    int num = 0, num2 = 0;
    for(char c : s){
	num+= c - '0';
    }
    num2 = num;
    s.PB('0');
    for(int i = 0; ; i++){
	f(i, num, start);
	if(i == 9)
	    break;
	int tmp = 0;
	while(s[tmp] == '9'){
	    s[tmp] = '0';
	    num2-= 9;
	    tmp++;
	}
	s[tmp]++;
	num2++;
	num+= num2;
    }
}

string S[30];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 1; i < 30; i++){
	S[i] = S[i-1] + "9";
    }
    for(string a = "0"; a[0] <= '9'; a[0]++){
	for(string b = "0"; b[0] <= '9'; b[0]++){
	    for(string c = "0"; c[0] <= '9'; c[0]++){
		for(int cnt1 = 0; cnt1 < 20; cnt1++){
		    for(int cnt2 = 0; (cnt1 + cnt2) * 9 + a[0] + b[0] + c[0] - '0' - '0' - '0' < 160; cnt2++){
			add(a + S[cnt1] + b + S[cnt2] + c);
		    }
		}
	    }
	}
    }
    int q;
    cin >> q;
    while(q--){
	int n, k;
	cin >> n >> k;
	if(mp[k][n] == "")
	    cout << -1 << "\n";
	else
	    cout << REV(mp[k][n]) << "\n";
    }
    return 0;
}