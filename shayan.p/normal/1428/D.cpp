#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e5 + 10;

void no(){
    cout << -1 << "\n";
    exit(0);
}

int a[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
    }
    vector<int> tr, vec;
    vector<pii> ans;
    int CN = n-1;

    int DEL = -1;
    int LS2 = -1, LS1 = -1;
    for(int i = 0; i < n; i++){
	if(a[i] == 3)
	    tr.PB(i);
	if(a[i] == 2)
	    LS2 = i;
	if(a[i] == 1)
	    LS1 = i;
    }
    if(!tr.empty()){
	if(tr.back() < LS2)
	    tr.PB(LS2);
	else if(tr.back() < LS1)
	    DEL = LS1, tr.PB(LS1);
	else
	    no();
	for(int i = 0; i < sz(tr)-1; i++){
	    ans.PB({tr[i], CN});
	    ans.PB({tr[i+1], CN});
	    CN--;
	}
    }
    for(int i = n-1; i >=0 ; i--){
	if(a[i] == 0 || a[i] == 3)
	    continue;	
	if(a[i] == 1 && i != DEL)
	    vec.PB(i);
	if(a[i] == 2){
	    if(vec.empty())
		no();
	    int id = vec.back();
	    vec.pop_back();
	    ans.PB({i, CN});
	    ans.PB({id, CN});
	    CN--;
	}
    }
    if(DEL != -1){
	vec.PB(DEL);
    }
    while(sz(vec) > 0){
	ans.PB({vec.back(), CN});
	vec.pop_back();
	CN--;
    }

    cout << sz(ans) << "\n";
    for(pii p : ans){
	cout << n - p.S << " " << p.F + 1 << "\n";
    }
    return 0;
}