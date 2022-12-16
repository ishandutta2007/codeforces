// Never let them see you bleed...
// Shayan.P  2020-06-11

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 1e7 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

int p[maxn];
int a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i = 2; i < maxn; i++){
	if(p[i] == 0)
	    for(int j = i; j < maxn; j+= i)
		p[j] = i;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
	cin >> a[i];
	b[i] = 1;
	int P = p[a[i]];	
	while(a[i] % P == 0)
	    a[i]/=P, b[i]*=P;
	if(a[i] == 1 || b[i] == 1)
	    a[i] = b[i] = -1;
    }
    for(int i = 0; i < n; i++){
	cout << a[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++){
	cout << b[i] << " ";
    }
    return cout << endl, 0;
}