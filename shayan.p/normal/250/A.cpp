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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n;
    cin >> n;
    vector<int> ans;
    int num = 0, beg = 0;
    for(int i = 0; i < n; i++){
	int x;
	cin >> x;
	if(num + (x<0) == 3)
	    ans.PB(i-beg), beg = i, num = 0;
	num+= x<0;
    }
    ans.PB(n-beg);
    cout << sz(ans) << "\n";
    for(int x : ans){
	cout << x << " ";
    }
    return cout << endl, 0;
}