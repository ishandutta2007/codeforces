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

string a, b, c;
int cta[26], ctb[26], ctc[26];

int main(){
	setup();

    cin >> a >> b >> c;
    for(char v : a) cta[v-'a']++;
    for(char v : b) ctb[v-'a']++;
    for(char v : c) ctc[v-'a']++;

    int ans = 0, use = 0;
    for(int bb=0; ; bb++){
        int cc = 0x7f7f7f7f;
        for(int i=0; i<26; i++)
            if(!ctc[i]) continue;
            else cc = min(cc, cta[i] / ctc[i]);

        if(bb + cc > ans){
            ans = bb + cc;
            use = bb;
        }

        for(int i=0; i<26; i++)
            if(cta[i] < ctb[i]) goto END;
            else cta[i] -= ctb[i];
    }

    END:

    for(int i=0; i<26; i++)
        cta[i] = 0;
    for(char v : a) cta[v-'a']++;

    for(int i=0; i<use; i++)
        cout << b;
    for(int i=use; i<ans; i++)
        cout << c;
    for(int i=0; i<26; i++){
        int rem = cta[i] - use * ctb[i] - (ans - use) * ctc[i];
        for(int j=0; j<rem; j++)
            cout << char('a'+i);
    }
    cout << endl;
}