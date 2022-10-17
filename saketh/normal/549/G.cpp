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
int ht[200005];

int main(){
	setup();
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> ht[i];
        ht[i] += i;
    }

    sort(ht, ht+N);

    for(int i=N-1; i>=0; i--){
        ht[i] -= i;
        if(i<N-1 && ht[i] > ht[i+1]){
            cout << ":(" << endl;
            return 0;
        }
    }

    for(int i=0; i<N; i++)
        cout << ht[i] << " ";
    cout << endl;
}