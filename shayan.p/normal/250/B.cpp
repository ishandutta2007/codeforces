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

    int q;
    cin >> q;
    while(q--){
	string ss;
	cin >> ss;
	string str = "";
	vector<string> ans;
	for(char ch : ss){
	    if(ch == ':')
		ans.PB(str), str = "";
	    else
		str+= ch;	    
	}
	ans.PB(str);

	int cnt = 0;
	for(string &s : ans){
	    if(s.empty())
		continue;
	    while(sz(s) < 4)
		s = "0" + s;
	    cnt++;
	}
	string ANS;
	cnt = 8-cnt;
	for(string &s : ans){
	    if(s.empty()){
		for(int i = 0; i < cnt; i++)
		    ANS+= "0000:";
		cnt = 0;
	    }
	    else{
		ANS+= s;
		ANS+= ":";
	    }
	}
	ANS.pop_back();
	cout << ANS << "\n";
    }
    return 0;
}