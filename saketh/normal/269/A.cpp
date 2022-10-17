#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100005;

int N;
pair<int, int> boxes[MAXN];

int main(){
    setup();
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> boxes[i].first >> boxes[i].second;
    sort(boxes, boxes+N);

    ll tot = 0;
    int siz = 0;

    for(int i=0; i<N; i++){
        while(siz < boxes[i].first && tot > 1){
            siz++;
            tot = (tot + 3) / 4;
        }
        siz = boxes[i].first;
        tot = max(tot, (long long) boxes[i].second); 
    }

    while(tot > 1){
        siz++;
        tot = (tot + 3) / 4;
    }

    if(siz == boxes[N-1].first) siz++;
    cout << siz << endl;
}