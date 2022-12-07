#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

string s[6] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int k;
	cin >> k;
	for (int i = 0; i < s[0].size(); i++) {
		for (int j = 0; j < 6; j++) if (k > 0 && s[j][i] == '#') {
			s[j][i] = 'O';
			k--;
		}
	}
	for (int i = 0; i < 6; i++) cout << s[i] << endl;

	return 0;
}