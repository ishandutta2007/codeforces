//yeah lets clear a page 2 problem first (successfully)

#include <iostream> //ray, scott picks problem
#include <cstdio> //steven, ok http://codeforces.com/problemset/page/2?order=BY_SOLVED_DESC
#include <algorithm> // scott, http://www.codeforces.com/problemset/problem/106/B
#include <cstring> //ray, richard get out

using namespace std; //steven
const int MAXN = 110; // scott

int N; //ray, wtf
//struct laptop { //steven, my bad
struct notlaptop { //scott ray li go
    int speed, ram, hdd, cost; //ray, sorry comp is freezing
    notlaptop(int a, int b, int c, int d) { // steven
        speed = a; ram = b; hdd = c; cost = d; //scott
    } //ray
    notlaptop()<% %>//steven
}//scott
;//ray

notlaptop ar[MAXN]; //steven

int main() //scott
{ //ray
scanf("%d", &N); //steven
for (int i = 0; i < N; i++) //scott
{ //ray, scott why you give me the boring lines gayboi, also lets race richard/travis/nathan after this;
int a,b,c,d; //steven
cin >> a >> b >> c >> d; //scott gogo ray li
ar[i] = notlaptop (a,b,c,d); //ray
}//steven also can we code simultaneously on different lines

int bcost = 1e9, res = -1; //scott this is the best cost found

for(int i=0; i<N; i++){ //ray
bool outdated = false; //steven, rpeng gave us his stypi want to troll it if we're losing?
for (int j = 0; j < N; j++) { //scott we won't lose dude
    if (ar[i].speed < ar[j].speed and ar[i].ram < ar[j].ram and ar[i].hdd < ar[j].hdd){ //ray
        outdated = true; break; }  } //steven, http://www.youtube.com/watch?v=O1U4aiEvudY&feature=youtu.be

if (!outdated){ //scott
    if (ar[i].cost < bcost){ //ray
           bcost = ar[i].cost, res = i + 1; //steven
    } //scott ray you can do the other }
} //ray, nig
} //steven, niggaaa

cout << res << "\n"; //scott
} //ray, dafuck are you talking about
//steven nigga you need to return 0 holy shit
//dude we compile error
//ray, holy shit steven you are so bad scott gogogogogo