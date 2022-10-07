#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <functional>
#include <cstring>
#include <complex>
#include <numeric> //did we miss a #include ...

const double EPS = 1e-10;

using namespace std; //gtfo i'm doing this
typedef long long ll;
typedef vector<int> vi;
#define pb push_back   // seriously??? yeah

#define fi first
#define se second
typedef pair<int, int> pii;

#define rep(i, a) for(int i = 0, _##i = (a); i < _##i; ++i) 
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)


//Zerg rusheeeeeee!!!!!!!!!!!!!!!
//wait guys this is easy right, sort by x coordinate and check adjacent pairs
//no, different directions, not same direction, it might be easier for an earlier particle to nuke you
//err what the first collision ALWAYS has to be an adjacent pair right oh sorry misread
//no, (1, 10000), (2, 1), (10, -1)
//collision doesn't count if they're moving in the same direction read the problem bro
//i say bin search and kill
//how to binary search? yarp
//say you want to look for a collision before time t
//then given an i, you find j < i s.t. the other one is after this one
//binary search on time makes sense but what about error 
//wait yeah so you just need to find the farthest any of the opposite direc particles have gone after bin search
// Don't you have "blocks" of forward and backward particles?  collisions between adjacent blocks?, oh right


//so, idea is... min_{j < i, v[j] > 0, v[i] < 0, (x[i] - x[j]) / (v[j] - v[i]))

// let's throw out particle... use arrays...

// uh, we should think of this as a 2d (the line + time dimension), and draw the trajectories of the backwards particles,
// do convex hull stuff
// then find where the forward trajectories intersect
// i think bin search is easiest?
// with the blocks I dont think you even need bin search.  for any pair of adjacent blocks you can do a time sweep (which is the furthest forward/backward over time) oh i see that is "convex hull stuff"
// but isn't bin search easier to code in that case?
//convex sounds right
// OH IT"S NOT A CYLINDER WHOOPS


//wait sort by x, maintain the farthest right any guy goes and check every guy going backwards, //binary search
//i like binary search scott go code it


//LET'S SUBMIT GOOOO
const double inf = (1.0E100); //HELP HELP HOW DO I DO INF is this right guys HELP ME I'M BAD AT CODING HOLY SHIT HOLY SHIT COME HELP dude you can't do 1e1000 it's too big for double
// that seems fine just submit damn it who said this?? i told you guys i suck at coding

const int MAXN = 500100;

int A[MAXN], V[MAXN];
bool F[MAXN];
int N;


bool works(double time) {//true if collision before time false otherwise
    double mx = -inf; //shit this is wrong guys // uh  //if first guy is backwards 
    for(int i = 0; i < N; ++i) {
        double a = A[i];
        double v = V[i];
        if (F[i]) {
            mx = max(mx, a + v * time);
        } else {
            double left = a - v * time;
            if (left < mx + EPS) {
                return true;
            }
        }
    }
    return false;
} //-steven check this for me


int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b < 0) {
            b = -b;
        } else {
            F[i] = true;
        }
        A[i] = a;
        V[i] = b;
    } //rewrote input for the 4th time <3 you typoed
    //oh did you fix it
    //also dumping vector it's probably the problem

//this is a bin search!!!!!!!! IT's wrong!! how is it wrong fixed iterations 1e-12, that's fixed
    double del = 1e11;//i changed this a bit is that fine? no this is not fine
// is penguin bin search an actual term //no, just some crazy leftover habbit...
    double ans = 0;
    while(del > 1e-10) {
      if(!works(ans + del)) ans += del; //is this right you need the ! i think it's right now ok submit????
      del *= double(.5); //shit jk what's going on guys is this around 100 iterations?
    }
    if(ans > 1e10) {
      puts("-1"); //what is this puts
    }
    else {
      printf("%0.20lf\n", ans);
    }
    return 0;
}

//someone clean this up we got CE


//WA case 1 now


//I'm laughing sooo hard at this
//why do we need ld... doubles is totally fine...
//omg can't believe it hought it was a cycle lol
//i don't understand why we had to rewrite the input 3 times

//CE again what's wrong

//it compiled
//WA test 1
//we were missing a default constructor for particle
//fixed a bug, subjit gogogogo

//test 18
//test 18 TLE
//no damn it
// wait, who the hell decided having particle was a good idea anyways? not me
// you declare arrays representing the input
// and specify what you do to them...
// dude that's a better strategy particle is useless
// i wasn't expecting v = -v, that was completely useless
// why not leave v negative and forget about the array of bools
// ok guys we are not close on time, n=10k gives us like 200ms
//why???
//submit now?