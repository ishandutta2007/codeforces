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

void setup(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
}

int N;
int rat[2005];

int main(){
	setup();
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> rat[i];

    for(int i=0; i<N; i++){
        int abv = 0;
        for(int j=0; j<N; j++)
            abv += int(rat[j] > rat[i]);
        cout << abv+1 << " ";
    }

    cout << endl;
}