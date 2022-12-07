#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;

int n, m;

string name[N], op[N];

int A[N], B[N];
int type[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> m;

	map<string, int> mem;
	mem["?"] = -1;
	for (int i = 0; i < n; i++) {
		string temp;
		string q;
		cin >> name[i] >> temp >> q;

		mem[name[i]] = i;

		if (q[0] == '1' || q[0] == '0') {
			type[i] = 1;
			op[i] = q;
		} else {
			A[i] = mem[q];
			cin >> op[i];
			cin >> q;
			B[i] = mem[q];
			
		}
	}
	string ans1 = "";
	string ans2 = "";
	for (int i = 0; i < m; i++) {
		int val[2];
		for (int j = 0; j < 2; j++) {
			int o[n];
			int sum = 0;
			for (int k = 0; k < n; k++) {
				if (type[k] == 1) {
					o[k] = op[k][i] - '0';
				} else {
					int a, b;
					if (A[k] == -1) a = j; else a = o[A[k]];
					if (B[k] == -1) b = j; else b = o[B[k]];
					if (op[k] == "XOR") a ^= b;
					else if (op[k] == "OR") a |= b; else a &= b;
					o[k] = a;
					sum += a;
				}
			}
			val[j] = sum;
		}
		if (val[0] <= val[1]) ans1.pb('0'); else ans1.pb('1');
		if (val[0] >= val[1]) ans2.pb('0'); else ans2.pb('1');
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}