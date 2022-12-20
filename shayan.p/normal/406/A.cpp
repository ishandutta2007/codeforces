#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e3 + 10;

bool sm;

int main(){    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++){
	    int x;
	    scanf("%d", &x);
	    if(i == j)
		sm^= x;
	}
    }
    int q;
    cin >> q;
    while(q--){
	int task;
	scanf("%d", &task);
	if(task == 3)
	    cout << sm;
	else{
	    int x;
	    scanf("%d", &x);
	    sm^= 1;
	}
    }
    return 0;
}