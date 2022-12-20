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

const int maxn = 1e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

bool is[maxn];
string nm[10];

int toInt(string s){
    stringstream ss;
    ss << s;
    int ans;
    ss >> ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 0; i < 10; i++)
	nm[i] = char('0' + i);
   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	string s;
	cin >> s;
	for(int j = 0; j < sz(s)-4; j++){
	    is[toInt(s.substr(j, 5))] = 1;
	}
    }
    int gold = 1;
    while(is[gold])
	gold++;
    string s;
    for(int i = 0; i < 5; i++)
	s+= char('0'+(gold%10)), gold/=10;
    reverse(s.begin(), s.end());

    s = "?" + s;
    
    for(int i = 0; i < 10; i++)
	cout << s + nm[i] + ">>" + nm[i] +  s << endl;
    cout << s + ">>" + "?" << endl;
    for(int i = 0; i < 9; i++)
	cout << nm[i] + "?" + "<>" + nm[i+1] << endl;
    cout << "9?>>?0" << endl;
    cout << "?<>1" << endl;
    cout << ">>" + s << endl;
    return 0;
}