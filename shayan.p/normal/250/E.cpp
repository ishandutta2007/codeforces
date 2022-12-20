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

const int maxn = 1e4 + 10, mod = 1e9 + 7;

string s[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
	cin >> s[i];
    int i = 0, j = 0, dir = 1;
    ll ans = 0;
    while(i < n-1){
	vector<int> vr;
	vector<int> vl;
	int er = -1, el = -1;
	for(int w = j; w < m; w++){
	    if(s[i][w] != '.')
		vr.PB(w);
	    if(s[i][w] == '#')
		break;
	    if(s[i+1][w] == '.'){
		er = w;
		break;
	    }
	}
	if(er == -1)
	    vr.PB(m);
	for(int w = j; w >= 0; w--){
	    if(s[i][w] != '.')
		vl.PB(w);
	    if(s[i][w] == '#')
		break;
	    if(s[i+1][w] == '.'){
		el = w;
		break;
	    }		
	}
	if(el == -1)
	    vl.PB(-1);
	reverse(vl.begin(), vl.end());
	reverse(vr.begin(), vr.end());
	while( (dir == 1 && sz(vr)) || (dir == -1 && sz(vl)) ){
	    if( sz(vl) && sz(vr) && (vr.back() == m || s[i][vr.back()] == '#') && (vl.back() == -1 || s[i][vl.back()] == '#') )
		return cout << "Never\n", 0;
	    if(dir == 1){
		ans+= vr.back() - j;
		j = vr.back()-1;
		if(vr.back() != m && s[i][vr.back()] == '+')
		    vr.pop_back();
		dir = -1;
	    }
	    else{
		ans+= j - vl.back();
		j = vl.back() + 1;
		if(vl.back() != -1 && s[i][vl.back()] == '+')
		    vl.pop_back();
		dir = 1;
	    }	    
	}
	if(dir == 1){
	    ans+= er - j + 1;
	    j = er;
	    i++;
	}
	else{
	    ans+= j - el + 1;
	    j = el;
	    i++;
	}	
    }
    return cout << ans << endl, 0;
}