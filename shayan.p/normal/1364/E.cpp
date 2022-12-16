// Never let them see you bleed...
// Shayan.P  2020-06-16

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 3010, mod = 1e9 + 7, inf = 1e9 + 10;

int n;
int arr[maxn];

int ask(int a, int b){
    cout << "? "<< a + 1 << " " << b + 1 << endl;
    int x;
    cin >> x;
    return x;
}
pii rnd(){
    while(true){
	int a = rand() % n, b = rand() % n;
	if(a == b)
	    continue;
	return {a, b};
    }
}

int ans[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    srand(time(0));
    cin >> n;
    vector<int> vec;    
    for(int i = 0; (1<<i) < n; i++){
	while(true){
	    pii p = rnd();
	    if(bit(ask(p.F, p.S), i) == 0){
		vec.PB(p.F);
		break;
	    }
	}
    }
    auto calc = [&](int pos){
		    int ans = 0;
		    for(int i = 0; i < sz(vec); i++)
			if(pos != vec[i] && bit(ask(vec[i], pos), i))
			    ans|= 1<<i;
		    return ans;
		};
    iota(arr, arr+n, 0);
    int pos = arr[0], num = calc(pos);
    for(int i = 1; i < n && num != 0; i++){
	if(ask(pos, arr[i]) == num){
	    pos = arr[i], num = calc(pos);
	}
    }
    for(int i = 0; i < n; i++){
	if(i != pos)
	    ans[i] = ask(pos, i);
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
	cout << ans[i] << " ";
    }
    return cout << endl, 0;
}