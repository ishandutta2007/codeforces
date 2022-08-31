#include <cstdio> //aho
#include <algorithm>
//#include <complex> //aho, this problem is wtf
#include <iostream> //scott
#include <map> //aho do we need this wait n<=5 let's casework bash

using namespace std; /*you look at the smallest / largest x,y coords
and then once that's checked you rescale coordinates and do it manually
k?
you could've done the same thing with like 300 rectangles
prolly an easier way to do this but i actually don't give a shit*/


int N; //steven
int x1[6], y1[6], x2[6], y2[6];;;;;;;

//typedef complex<int> point; //steven, doing it the right way and you forgot ;

int main() {;;;;;;;;;;;;//scott
    scanf("%d", &N);;;;;//aho
	for (int i = 0; i < N; i++) {;;;;;;;;;;;;//scott you're missing a few ;s
        ;;;;;scanf("%d %d %d %d", x1+i,y1+i,x2+i,y2+i);;;;;;;;;;;;;;;;;;;;;;;;;;;;;;//aho
	};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;//scott
    map<int,int> mymap;;;;;;;;;;;//aho, throw everything in a map?

	for (int i = 0; i < N; i++) {;;;;;;;;;;;;;;;;;;;; //scott yeah sounds good
        mymap[x1[i]]=mymap[x2[i]]=mymap[y1[i]]=mymap[y2[i]]=1;;;;;;;;;;;;;;;;//aho, we'll make it go increasing later
	};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; //scott stop making me do these
    #define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)//steven thanks for using my #define you suck

	for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); it++) //scott
        ; int cnt = 0; //steven thanks for using my #define you suck
	for (map<int,int>::iterator it = mymap.begin(); it != mymap.end(); it++) //scott;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        it->second = ++cnt;;;;;;;;;;;;;;;;//steven

	int xlo = 1e9, xhi = -1, ylo = 1e9, yhi = - 1;;;;;;;;;;;;;;;;;; //scott no we have to check SQUARE
    for(int i = 0; i < N; ++i) {//steven, first do your thing
		xlo = min (xlo, x1[i]); //scott it's in order yo
        ylo = min(ylo,min(y1[i],y2[i]));//steven you noob i'm being safe;;;;
		xhi = max (xhi, x2[i]); //scott it's in order yo ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        yhi=max(yhi,max(y1[i],y2[i]));//steven
	};;;;;;;;;;;;;;;;;;;;;;;;;;;;//scott yeah i'm being safe with my ;s
    
    bool ans = true;;;;;;;;;; //steven you do everything lol

	int ccount[15][15] = {};;;;;;;; //scott just make sure count is 1 for all
    int xw = xhi - xlo, yw = yhi - ylo; //steven check this first
	ans = (xw == yw); //scott we can do if !ans later bro
    
    for(int i = 0; i < N; ++i) { //steven
		for (int j = mymap[x1[i]]; j < mymap[x2[i]]; j++) //scott hmm checking in the end might be kinda annoying
            for(int k = mymap[y1[i]]; k < mymap[y2[i]]; ++k) { //steven we made it n^2log^2n, we check mymap[xlo]..mymap[xhi]
				ccount[j][k]++; //scott this is clearly n^3 bro
            }};;;;;//steven sry you suck at writing {s    i said for(int i = mymap[xlo]; i < mymap[xhi]; ++i) doesn't that work also i did one indexing lul  you need i = 1; i <= cnt; ++i. i thought you would be more used to 1 indexing idk

	for (int i = 1; i <= cnt; i++) for (int j = 1; j <= cnt; j++) if (mymap[xlo] <= i && i < mymap[xhi] && mymap[ylo] <= j && j < mymap[yhi]) //scott
{ //steven this is correct.
if (ccount[i][j] != 1) ans = false; } else { //scott
if (ccount[i][j]) ans = false; //steven
} //scott;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

int demi;//steven we're done right, let's do a ternary as a tribute
if (ans) cout << "YES\n"; //scott
else cout << "NO\n";;;;;;;;;;;;;; //steven fine
//system ("Pause"); //scott my tribute
} //steven i didn't return 0 as my tribute  lol compilation error using your y1 you tricky