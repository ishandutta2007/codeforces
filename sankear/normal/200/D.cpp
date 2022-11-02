#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

char s[100], buf[100];
string procedureName[1010];
vector <string> types[1010];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		gets(s);
		bool first = true;
		int len = strlen(s), j = 0;
		while(j < len){
			if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')){
				string cur = "";
				while(j < len && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
					cur += s[j++];
				}
				if(first){
					procedureName[i] = cur;
					first = false;
				}
				else{
					types[i].pb(cur);
				}
				continue;
			}
			j++;
		}
	}
	int m;
	scanf("%d", &m);
	map <string, string> type;
	for(int i = 0; i < m; i++){
		scanf("%s %s", buf, s);
		type[s] = buf;
	}
	int k;
	scanf("%d\n", &k);
	for(int i = 0; i < k; i++){
		gets(s);
		vector <string> need;
		string name;
		bool first = true;
		int len = strlen(s), j = 0;
		while(j < len){
			if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')){
				string cur = "";
				while(j < len && ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
					cur += s[j++];
				}
				if(first){
					name = cur;
					first = false;
				}
				else{
					need.pb(type[cur]);
				}
				continue;
			}
			j++;
		}
		int ans = 0;
		for(int j = 0; j < n; j++){
			if(procedureName[j] == name && sz(types[j]) == sz(need)){
				bool fl = true;
				for(int z = 0; z < sz(need); z++){
					if(types[j][z] == "T" || need[z] == types[j][z]){
						continue;
					}
					fl = false;
					break;
				}
				if(fl){
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}