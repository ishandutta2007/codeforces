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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int q;
    cin >> q;
    while(q--){
	int n;
	cin >> n;
	int lst = -1, cnt0 = 0, cnt1 = 0;
	bool srt = 1;
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    srt&= lst <= x;
	    lst = x;
	}
	for(int i = 0; i < n; i++){
	    int x;
	    cin >> x;
	    (x & 1 ? cnt1 : cnt0)++;
	}
	if(srt || (cnt0 > 0 && cnt1 > 0))
	    cout << "Yes\n";
	else
	    cout << "No\n";
    }
    return 0;
}