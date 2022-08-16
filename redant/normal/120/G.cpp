
#include<iostream>
#include<sstream>
#include<cstdio>
#include<memory.h>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#include<set>
#include<deque>
#include<climits>
#include<utility>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SL ({long long _x; scanf("%lld",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define sscan(n) scanf("%s",n)
#define MP make_pair
#define PB push_back
#define LL long long
#define _MAX 10000
#define FILL(a,x) memset(a,x,sizeof a)
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PI; 
typedef pair <LL, PI> PLPI;
#define SZ(a) int((a).size()) 
#define ALL(c) (c).begin(),(c).end() 
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = SI, t = SI;
	int a[2][110],b[2][110];
	REP(i,n) {a[0][i] = SI; b[0][i] = SI; a[1][i] = SI; b[1][i] = SI;}
	int m = SI;
	string card[110];
	int c[110];
	REP(i,m) {cin >> card[i]; c[i] = SI; }
	queue <int> state;
	REP(i,m) state.push(i);
	int d[110][110];
	VI perf[110];
	REP(i,n) REP(j,m) d[i][j] = 0;
	int turn = 0,team = 0;
	int spent = 0;
	while(!state.empty())
	{
		int cur = state.front(); state.pop();
		int rem = max(1,c[cur] - (a[turn][team] + b[1-turn][team]) - d[team][cur]);
	//	printf("cur = %s, team = %d, turn = %d and rem = %d\n",card[cur].c_str(),team,turn,rem);
		if(spent + rem <= t)
		{
			perf[team].PB(cur);
			spent += rem;
			if(spent == t)
			{
				spent = 0;
				++team;
				if(team == n)
				{
					team = 0;
					turn = 1-turn;
				}
			}
		}
		else
		{
			state.push(cur);
			d[team][cur] += (t - spent);
			spent = 0;
			++team;
			if(team == n)
			{
				team = 0;
				turn = 1-turn;
			}
		}
	}
	REP(i,n)
	{
		printf("%d",SZ(perf[i]));
		REP(j,SZ(perf[i])) printf(" %s",card[perf[i][j]].c_str());
		printf("\n");
	}
	return 0;
}