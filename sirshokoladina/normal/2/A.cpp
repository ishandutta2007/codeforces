#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int,int> pii;
typedef long long int64;
typedef long double real;

#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define forn(i,n) FORN(i,0,n)
#define ford(i,n) FORD(i,0,n)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define length(a) ((int)(a).size())
#define high(a) (length(a)-1)
#define last(a) a[high(a)]
#define all(a) a.begin(),a.end()
#define norm(a) {sort(all(a));a.erase(unique(all(a)),a.end());}

map<string,int> tuda;
vector<string> suda;
int score[10000];

string s[10000];
int x[10000];
bool can[10000];

int main(){
	int n;
	cin>>n;
	forn(i,10000)
		score[i]=can[i]=0;
	forn(i,n){
		cin>>s[i]>>x[i];
		if(i==0 || suda[tuda[s[i]]]!=s[i]){
			tuda[s[i]]=suda.size();
			suda.pb(s[i]);
		}
		score[tuda[s[i]]]+=x[i];
	}
	int mx=0;
	forn(i,suda.size())
		mx=max(mx,score[i]);
	forn(i,n)
		if(score[i]==mx)
			can[i]=1;             
	forn(i,10000)
		score[i]=0;
	forn(i,n){
		score[tuda[s[i]]]+=x[i];
		if(score[tuda[s[i]]]>=mx && can[tuda[s[i]]]){
			cout<<s[i];
			return 0;
		}
	}
	return 0;
}