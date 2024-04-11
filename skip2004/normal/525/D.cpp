#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
struct pr{int x,y;};
const int N = 2010;
char s[N][N];
std::queue<pr>q;
int n,m;
inline void judge(int x,int y){
	if(1 <= x && x <= n && 1 <= y && y <= m && s[x][y]!='.' && (
		s[x-1][y]=='.'&& s[x][y-1]=='.'&& s[x-1][y-1]=='.' ||
		s[x+1][y]=='.'&& s[x][y-1]=='.'&& s[x+1][y-1]=='.' ||
		s[x-1][y]=='.'&& s[x][y+1]=='.'&& s[x-1][y+1]=='.' ||
		s[x+1][y]=='.'&& s[x][y+1]=='.'&& s[x+1][y+1]=='.'
		)) {
		s[x][y]='.';
		q.push((pr){x,y});
		return ;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>s[i]+1;
	rep(i,1,n)rep(j,1,m)judge(i,j);
	for(;q.size();){
		pr x=q.front();q.pop();
		rep(i,-1,1)rep(j,-1,1)if(i||j)judge(x.x+i,x.y+j);
	}
	rep(i,1,n)cout<<s[i]+1<<'\n';
}