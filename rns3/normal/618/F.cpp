#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define M 2000001

int mpa[M], mpb[M];


vector<int> v[M], va[M], vb[M];
set<int> seta, setb;
set <int> :: iterator it;

int main() {
	//freopen("ff.in", "r", stdin);
	int n;
    scanf("%d", &n);
    ll suma = 0, sumb = 0;
    for(int i = 1; i <= n; i ++) {
		int x;
    	scanf("%d", &x);
    	mpa[x] ++;
    	seta.insert(x);
		va[x].push_back(i);
		suma += x;
    }
    for(int i = 1; i <= n; i ++) {
    	int x;
    	scanf("%d", &x);
    	mpb[x] ++;
    	setb.insert(x);
		vb[x].push_back(i);
        sumb += x;
    }
    int CNT = 0;
	while(1) {
		CNT ++;
		if(suma == sumb) break;
        if(suma > sumb) {
            ll z = suma - sumb;
			it = seta.lower_bound(z);
			if(it == seta.end()) it --;
            int x = *it;
            va[x].pop_back();
            suma -= x;
            mpa[x] --;
            if(mpa[x] == 0) seta.erase(x);
        }
        else {
        	ll z = sumb - suma;
			it = setb.lower_bound(z);
			if(it == setb.end()) it --;
			int x = *it;
			vb[x].pop_back();
			sumb -= x;
			mpb[x] --;
			if(mpb[x] == 0) setb.erase(x);
        }
	}
    int sza = 0, szb = 0;
    for(int i = 1; i <= n; i ++) sza += va[i].size();
    for(int i = 1; i <= n; i ++) szb += vb[i].size();
    printf("%d\n", sza);
    for(int i = 1; i <= n; i ++) {
    	for(int j = 0; j < va[i].size(); j ++) printf("%d ", va[i][j]);
    }
    puts("");
    printf("%d\n", szb);
     for(int i = 1; i <= n; i ++) {
    	for(int j = 0; j < vb[i].size(); j ++) printf("%d ", vb[i][j]);
    }
    puts("");
}