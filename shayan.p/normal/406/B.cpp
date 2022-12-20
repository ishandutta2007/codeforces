#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e6 + 10, SIX = 1e6;

int n;
bool is[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
	int x;
	scanf("%d", &x);
	--x;
	is[x] = 1;
    }
    vector<int> can, ret;
    int need = 0;
    for(int i = 0; i < SIX/2; i++){
	if(is[i] || is[SIX-1-i]){
	    if(is[i] && is[SIX-1-i])
		need++;
	    else if(is[i])
		ret.PB(SIX-1-i);
	    else if(is[SIX-1-i])
		ret.PB(i);
	}
	else{
	    can.PB(i);
	}
    }
    while(need--){
	int x = can.back();
	ret.PB(x);
	ret.PB(SIX-1-x);
	can.pop_back();
    }
    printf("%d\n", sz(ret));
    for(int x : ret)
	printf("%d ", x+1);
    return 0;
}