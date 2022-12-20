// I think of what the world could be, A vision of the one I see, A million dreams is all it's gonna take

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

vector<int> v[40];
int num[40];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    while(n--){
	int x;
	cin >> x;
	for(int i = 0; i < 31; i++){
	    if(bit(x, i)){
		v[i].PB(x);
		if(sz(v[i]) == 1)
		    num[i] = x;
		num[i]&= x;
	    }
	}
    }
    int ans = -1;
    for(int i = 0; i < 31; i++){
	if(v[i].empty())
	    continue;
	if(__builtin_ctz(num[i]) == i)
	    ans = i;
    }
    cout << sz(v[ans]) << endl;
    for(int x : v[ans])
	cout << x << " ";
    return cout << endl, 0;
}