/*#include <cstdio>//steven C
#include <iostream>//eugene


using namespace std; //scott


int A, B; //steven




int main(){ // eugene
    cin >> A >> B; //scott
    string s; //steven
cin >> s; // eugene

    int cx = 0, cy = 0; //scott
    for(int i = 0; i < int(s.size()); ++i) {//steven
        if (s[i] == 'U'){//eugene
            cy++; //scott
        } else if (s[i] == 'R') { //steven
            cx++;//eugene 
        } else if (s[i] == 'L') { //scott        
            --cx; //steven
        } else { // eugene
            cy--; //scott
        } //steven
 }// eugene       
 
 int nx = cx, ny = cy; cx = 0, cy = 0; //scott we repeat now yeah? we should type up a bool to check if it works
 
 for(int i = 0; i < int(s.size()); ++i) { //steven be careful of "negative cycle" i got 10 hacks on that just cout and break
    if (s[i] == 'U') {//eugene
        cy++; //scott
    } else if (s[i] == 'D') {//steven
    cy--;//eugene you fag
    } else if (s[i] == 'L') {//scott
        --cx; //steven lol
    } else { // eugene
        cx++; //scott you got me
    } //steven
    // eugene: scott you dumbass
    
    i += 0; //scott
    if (cx == A && cy == B) { //steven we forgot this case we were supposed to check in the beginning... trust me i got 10 hacks on this problem
        cout << "Yes\n"; // eugene who gives a shit just go
        return 0; //scott
    } else if (A == 0 && B == 0) {//steven you're right scott my bad
        cout << "Yes\n"; //scott
    return 0; // eugene
    } //steven finish this up guys
    i -= -0; //scott looks ok
    i -= 0; // eugene hurry up scott your turn
    if ((nx != 0 && ny != 0 && (A - cx) / nx > 0 && (A - cx) % nx == 0 && (B - cy) % ny == 0 && (A - cx) / nx == (B - cy) / ny)) //steven, loks right??
    { //scott
    cout << "Yes\n"; //eugene brb
    return 0; //steven
    } //scott line 54 pls
    } //eugene ez 
    cout << "No\n";//steven line 54 pls pls
    return 0; } //scott
//comp error noobs

//steven fix pls
    
//scott you fix you're the gold medalist here    */
    #include <cstdio>

const int MAXN = 110;
char str[MAXN];
int a, b;

typedef long long ll;

bool can(ll a, ll b, int c, int d) {
    if (d == 0) {
		if (b != 0) return false;
		if (c == 0) return a == 0;
		if (a % c != 0) return false;
		if (a / c < 0) return false;
		return true;
	}
	if (c == 0) {
		if (a != 0) return false;
		if (b % d != 0) return false;
		if (b / d < 0) return false;
		return true;
	}
	if (a % c != 0 || b % d != 0) return false;
	ll da = a / c;
	ll db = b / d;
	return da >= 0 && da == db;
}

bool go() {
	int x = 0, y = 0;
	scanf("%d %d", &a, &b);
	scanf("%s", str);
	for(int i = 0; str[i]; ++i) {
		if (str[i] == 'U') {
			++y;
		} else if (str[i] == 'D') {
			--y;
		} else if (str[i] == 'L') {
			--x;
		} else if (str[i] == 'R') {
			++x;
		}
	}
	int perx = x;
	int pery = y;
	x = 0;
	y = 0;
	for(int i = 0; str[i]; ++i) {
		ll dx = a - x;
		ll dy = b - y;

		if (can(dx, dy, perx, pery)) return true;

		if (str[i] == 'U') {
			++y;
		} else if (str[i] == 'D') {
			--y;
		} else if (str[i] == 'L') {
			--x;
		} else if (str[i] == 'R') {
			++x;
		}
	}
	return false;
}

int main() {
	if (go()) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}