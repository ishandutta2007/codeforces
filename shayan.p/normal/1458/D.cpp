#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 5e5 + 10;

int _cnt[2 * maxn];

int& cnt(int i){
    return _cnt[i + maxn];
}
void clear(int n){
    for(int i = -n; i <= n; i++)
	cnt(i) = 0; 
}

void build(int x, vector<int> &v){
    int nxt = x+1, prv = x-1;
    if(x < 0)
	swap(nxt, prv);
    for(int i = 0; i < cnt(x); i++){
	v.PB(prv);
	if(i == 0 && x < 0)
	    build(nxt, v);
	else if(i == cnt(x)-1 && x > 0)
	    build(nxt, v);
	else
	    v.PB(x);
    }
    cnt(x) = 0;
    v.PB(prv);
}

void operator += (vector<int> &a, vector<int> b){
    for(int x : b)
	a.PB(x);
}
void print(vector<int> v){
    for(int x : v)
	cout << x << " * ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	string s;
	cin >> s;
	int n = sz(s);
	clear(n);
	int sm = 0, MN = 0, MX = 0;
	for(char c : s){
	    sm+= (c == '1' ? 1 : -1);
	    cnt(sm)++;
	    MN = min(MN, sm);
	    MX = max(MX, sm);
	}
	for(int i = sm; i < 0; i++){
	    cnt(i)--;
	}
	for(int i = sm; i > 0; i--){
	    cnt(i)--;
	}	    
	for(int i = MN; i < 0; i++){
	    cnt(i+1)-= cnt(i);
	}
	for(int i = MX; i > 0; i--){
	    cnt(i-1)-= cnt(i);
	}
	//	cout << "HEY " << sm << endl;
	vector<int> ans;
	if(sm >= 0){
	    vector<int> vec;
	    for(int i = sm; i >= 0; i--){
		vec.clear();
		build(i+1, vec);

		//	print(vec);
		
		reverse(vec.begin(), vec.end());
		ans+= vec;
	    }
	    vec.clear();
	    build(-1, vec);

	    //	    print(vec);
	    
	    reverse(vec.begin(), vec.end());
	    ans.pop_back();
	    ans+= vec;
	    reverse(ans.begin(), ans.end());
	}
	else{
	    build(-1, ans);
	    ans.pop_back();
	    build(1, ans);
	    for(int i = -1; i >= sm; i--){
		build(i-1, ans);
	    }
	}
	for(int i = 1; i < sz(ans); i++)
	    cout << (ans[i] - ans[i-1] == 1 ? '1' : '0');
	cout << "\n";
    }
    return 0;
}