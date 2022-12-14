#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

const int Maxn = 1234;
ld dp[Maxn][Maxn][2];
ld drag(ld w,ld b);

ld pri(ld w,ld b){
	if(b < 0)
		return 0;
	if(dp[(int)w][(int)b][0] != -1)
		return dp[(int)w][(int)b][0];
	if(!w)
		return 0;
	dp[(int)w][(int)b][0] = 0;
	ld tmp = (w)/(b+w) + ((b)/(b+w))*drag(w,b-1);
	if(tmp != tmp)
		return 0;
	return dp[(int)w][(int)b][0] = tmp;
}
ld drag(ld w,ld b){
	if(b < 0)
		return 0;
	if(dp[(int)w][(int)b][1] != -1)
		return dp[(int)w][(int)b][1];
	if(!w)
		return 0;
	dp[(int)w][(int)b][1] = 0;
	ld tmp = (b/(b+w))*((((b-1)/(b+w-1))*pri(w,b-2))+(((w)/(b+w-1))*pri(w-1,b-1)));
	if(tmp != tmp)
		return 0;
//	cerr << w << " " << b << " jav " << pri(w,b-2)*((b-1)/(b+w-1)) << " " << pri(w-1,b-1) << " Zarib " << w/(b+w-1) << " " << (b-1)/(b+w-1) << " " << b/(b+w) << endl; 
	return dp[(int)w][(int)b][1] = tmp;
}
int main(){
	int w,b;
	cin >> w >> b;
	for(int i = 0; i <= w;i++){
		for(int j = 0; j <= b;j++){
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}
	cout.precision(10);
	cout << pri(w,b) << endl;
//	for(int i = 0; i <= w;i++){
//		for(int j = 0; j <=b;j++){
//			cout << dp[i][j][0] << " :D " << dp[i][j][1] << " i va j " << i << " " << j << endl;
//		}
//	}
}