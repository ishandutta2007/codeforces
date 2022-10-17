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

string s, t;

int main(){
    setup();

    cin >> s >> t;

    string z = s;

    int l = -1;
    for(int i=0; i<s.size(); i++){
        if(s[i] != 'z') l = i;
    }

    if(l == -1) { cout << "No such string\n"; return 0; }

    z[l]++;
    for(int j=l+1; j<s.size(); j++)
        z[j] = 'a';
    
    if(z < t) cout << z << "\n";
    else cout << "No such string\n";
}