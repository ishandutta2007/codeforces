#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

int N, M;
char g[64][64];

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
}

int main(){
	setup();

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> g[i][j];

    int ans = 0;
    for(int i=1; i<N; i++)
        for(int j=1; j<M; j++){
            string chars;
            chars += g[i-1][j-1];
            chars += g[i-1][j];
            chars += g[i][j-1];
            chars += g[i][j];
            sort(chars.begin(), chars.end());
            ans += chars == "acef";
        }

    cout << ans << endl;
}