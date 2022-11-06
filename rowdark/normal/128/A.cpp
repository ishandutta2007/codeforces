#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
typedef pair<long,long> pii;


const double pi = 3.1415926535;
const double eps = 1e-4;
char M[10][10];

inline bool is(const long x,long y,long z){
	y-=x;
	if(-1<y&&y<8) return M[y][z]!='S';
	return 1;
}
bool in[50][10][10];
const long dx[9]={0,1,0,-1,0,1,-1,-1,1};
const long dy[9]={0,0,1,0,-1,1,-1,1,-1};

bool dfs(long t,long x,long y){
	in[t][x][y]=1;
	if(is(t,x,y)){
		if(8<t) return 1;
		if(x==0&&y==7) return 1;
		for(long ii=0;ii<9;++ii){
			if(-1<x+dx[ii]&&x+dx[ii]<8&&-1<y+dy[ii]&&y+dy[ii]<8&&!in[t+1][dx[ii]+x][dy[ii]+y]&&is(t,x+dx[ii],y+dy[ii]))
				if(dfs(t+1,dx[ii]+x,dy[ii]+y))
					return 1;
			}
		}
	return 0;
}

int main(){
	for(long i=0;i<8;++i)
		scanf("%s",M[i]);
	printf("%s\n",dfs(0,7,0)?"WIN":"LOSE");
	scanf("%s",M[0]);
	return 0;
}