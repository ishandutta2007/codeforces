#include <iostream>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)

int n;
int co[2][2];

int main(){
    cin >> n;
    rep(i, n){
	int a, b, c;
	cin >> a >> b >> c;
	a--;
	co[a][0] += b; co[a][1] += c;
    }
    rep(i, 2){
	if(co[i][0] >= co[i][1]) cout << "LIVE" << endl;
	else cout << "DEAD"<< endl;
    }
    return 0;
}