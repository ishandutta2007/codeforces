//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;

string ans = "";
bool ok = 1;
void input() {
	if(!ok) return;
	string s;
	if(cin>>s) {
		if(s == "int") ans += "int";
		else {ans += "pair<"; input(); ans += ","; input(); ans += ">";}
	}
	else ok = 0;
}

int main() {
	scanf("%*[^\n]"); input();
	string qwq; getline(cin, qwq);
	if(!ok || qwq.size()) puts("Error occurred");
	else cout<<ans<<endl;
	return 0;
}