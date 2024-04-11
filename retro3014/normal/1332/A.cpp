#include <stdio.h>
#include <iostream>
#include <vector>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1;

int T;
int a, b, c, d;
int x, y, x1, y1, x2, y2;

int main(){
	scanf("%d", &T);
	while(T--){
		bool tf = true;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
		if(a>b){
			if(x-a+b<x1)	tf = false;
		}else if(a<b){
			if(x+b-a>x2)	tf = false;
		}else{
			if(a!=0 && x==x1 && x==x2)	tf = false;
		}
		if(c>d){
			if(y-c+d<y1)	tf = false;
		}else if(c<d){
			if(y+d-c>y2)	tf = false;
		}else{
			if(d!=0 && y==y1 && y==y2)	tf = false;
		}
		if(tf){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}