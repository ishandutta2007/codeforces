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

int N;
bool cont[128][128];
bool inp[128];
int need[128];


void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
}

int main(){
	setup();
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            char c;
            cin >> c;
            cont[i][j] = c=='1';
        }

    for(int i=0; i<N; i++) cin >> need[i];

    int TG = N;
    while(TG){
        bool found = false;
        for(int i=0; i<N; i++){
            if(inp[i]) continue;
            if(need[i] >= 1) continue;

            inp[i] = true;
            for(int j=0; j<N; j++){
                if(cont[i][j])
                    need[j]--;
            }
            found = true;
            TG--;
        }
        if(!found || TG == 0){
            cout << N-TG << endl;
            for(int i=0; i<N; i++)
                if(inp[i])
                    cout << i+1 << " ";
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}