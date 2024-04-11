#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000;

bool way[size][size];
int n, m, k;
int v[size], u[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    vector <int> allp;

    scanf("%d%d", &m, &k);
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &v[i], &u[i]);
    	allp.pb(v[i]);
    	allp.pb(u[i]);
    }

    sort(allp.begin(), allp.end());

    allp.resize(unique(allp.begin(), allp.end()) - allp.begin());
    n = allp.size();

    for (int i = 0; i < m; i++) {
    	v[i] = lower_bound(allp.begin(), allp.end(), v[i]) - allp.begin();
    	u[i] = lower_bound(allp.begin(), allp.end(), u[i]) - allp.begin();
    }

    for (int i = 0; i < m; i++) {
    	way[v[i]][u[i]] = true;
    	way[u[i]][v[i]] = true;
    }

    for (int i = 0; i < n; i++) {
    	vector <int> psb;

    	int b = 0;

    	for (int j = 0; j < n; j++) {
    		if (j == i)
    			continue;
    		if (way[i][j])
    			b++;	
    	}

    	for (int j = 0; j < n; j++) {
    		if (j != i && !way[i][j]) {
    			int a = 0;
    			for (int p = 0; p < n; p++) {
    				if (p != i && p != j && way[i][p] && way[p][j]) {
    					a++;
    				}
    			}

    			if (a * 100 >= b * k)
    				psb.pb(allp[j]);
    		}
    	}

    	printf("%d: %d", allp[i], (int) psb.size());
    	for (int p = 0; p < (int) psb.size(); p++)
    		printf(" %d", psb[p]);
    	printf("\n");
    }

    return 0;
}