// Never let them see you bleed...
// Shayan.P  2020-04-15

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn = 110, mod = 1e9 + 7, inf = 1e9 + 10;

int nw[maxn], did[maxn];
int _X, _Y;

pii ask(int id){
    if(nw[id] != -1)
	nw[id]++;
    did[id]++;
    pii p;
    cout << "+ " << id+1 << endl;
    cin >> p.F >> p.S;
    int A = p.F-_X, B = p.S-_Y;
    _X = p.F, _Y = p.S;
    if(A != 0){
	for(int i = 2; i <= maxn; i++){
	    if((i * (i-1) / 2) == A){
		nw[id] = i+1;
		break;
	    }
	}
    }
    return {A, B};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    memset(nw, -1, sizeof nw);
    
    int n;
    cin >> n;
    cin >> _X >> _Y;
    
    pii A = ask(0), B = ask(1), C = ask(2);    
    if(B.S == 0)
	nw[2] = 1;
    if(nw[2] == -1)
	nw[2] = 2;
    pii X = ask(0);
    if(nw[0] == -1)
	nw[0] = 2;
    nw[1] = X.S / nw[2];
    if(C.S == (nw[0]-1) * nw[1])
	nw[3] = 0;
    pii LST = {-1, -1};
    for(int i = 3; i < n-1; i++){
	pii X = ask(i);
	if(nw[i] == -1)
	    nw[i] = 2;
	if(X.S == nw[i-1] * nw[i-2])
	    nw[i+1] = 0;
	LST = X;
    }
    if(LST.S == -1){
	nw[n-1] = (C.S - (nw[0]-1) * nw[1]) / nw[1];
    }
    else{
	nw[n-1] = (LST.S - nw[n-4] * nw[n-3]) / nw[n-3];
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
	cout << nw[i] - did[i] << " ";
    }
    return cout << endl, 0;
}