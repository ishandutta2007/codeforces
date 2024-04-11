#include <iostream> //steven, i give up on cstdio http://codeforces.com/problemset/problem/225/C
#include <vector> //scott dude so hard how do you even do this
#include <cstring> //ray no be a man dude
#include <algorithm> //steven
#include <map> //scott seriously how do you do this


using namespace std; //ray, ok first input, then compute num # per column, there's only one tricky line gogogogog scott

const int MAXN = 1100; //steven, scott it's dp. no one start main yet.
const int MAXM = 1100; //scott idk what you guys are doing

int N, M, X, Y; //ray

int sums[MAXN]; //steven, let's do dp with recursion i like it that way
int dp[MAXN]; //scott
bool vis[MAXN][MAXN]; // ray

int getdp(int n) { //steven
n+=0; //scott
n+=0; //ray
int &res = dp[n]; if (res) return res - 1; //steven now just iterate on something
for (int i = X; i <= Y; i++) { //scott size of last banner hey so is sums # of '.' or what
    n+=0; // ray, yeah ok
} //steven shit we need to know if the previous was black or white or blank my bad. let's make a dp[MAXN][3]?
//} //scott
return 0; } //ray
int DP[MAXN][3]; //steven sums will be # of . i guess
int blah; //scott
bool VIS[MAXN][3]; //ray yeah ok gogo

int getDP(int n, int prvcol) { //steven actually prvcol = 0 or 1 so actually up to 2. we'll getDP(0,1) and getDP(0,0)
int &res = DP[n][prvcol]; if (res) return res - 1; //scott be careful with the caps
/*for(int i=X; i<=Y; i++){ // ray, oh wait nvm yeah whoops
    break; } int sum = 0; for(int i = n; i < N; ++i) {//steven yeah you're slow we don't need to precompute lol just compute as you go
n+=0;//scott    
n+=0; //ray
sum += sums[i]; //steven do you guys want me to carry? 
if (i >= n + X && i <= n + Y){ //scott don't you have to getDP dude DP is set to 0 initially also you need to add in sum dude "if (res) return res - 1" screws up
    DP[n][prvcol] = min (DP[n][prevcol], sum + getDP (i, 1 - prevcol)); //ray, lets set it to INF in main
} //steven this thing is wrong let's rewrite this. so >= n + X - 1, < n + Y, and yeah we need to initialize to inf.
//dude you cannot initialize to inf you have int &res = DP[n][prvcol]; if (res) return res - 1
//initialize after that. can i comment out this shitty code
//go for it
*/
res = 1 << 30; int sum = 0; //steven, scott 
n+=0; //scott
n+=0;//ray lol
for(int i = n; i < M; ++i) { //steven bleh n + X - 1, < n + Y.
sum += sums[i]; //scott err isn't it <= wtf?
    if (i >= n + X - 1 && i < n + Y) { //ray yeah so [n,n+X-1] up to [n, n+Y-1];
        int realsum = prvcol == 1 ? (i - n + 1) * N - sum : sum; //steven oops we'll figure out the == 1 in main. RAY YOUR TURN
        DP[n][prvcol] = min (DP[n][prvcol], realsum + getDP (i+1, 1 - prvcol));//scott hey we need if (n == N) case at top actually we can do it after this loop
    } //ray, wait did you ever memo???
} if (n == M) res = 0;// return res++; //steven is this right i want to make sure i didn't mess up;
//res = DP[n][prvcol]; //scott wait my line does nothing steven you need ++res not res++
//return ++res  ; //yeah lol

//steven you guys are dumb niggers it's res++ i do this in all my dp trust me return ++res makes your returned answer 1 higher
//dude it is ++res you return res-1 ++res makes it same as DP[n][prvcol] it's pre-fix update
//I'VE BEEN DOING THIS FOR ALL MY DP HOLY SHIT IT'S RES++ lol  you don't return the DP value that's why you do return res - 1 up there
//wtf are you trying to do why don't you just res++; return res - 1; that works too dawg but return res++ is sexier
return res++; //ray, scottsaho?//ok let's just move on GOGOGGOGOGOGOGO SCOTT JOHNNY HO WA ON TEST 1
} //steven scotts aho hurry up we need to do sums

int main() {//scott
    cin >> N >> M >> X >> Y; // ray gogo, wait jk
    for(int i = 0; i < N; ++i) {//steven no you don't just store it in sums
        for (int j = 0; j < M; j++){ //scott
        } string s; cin >> s; //ray
        for(int j = 0; j < M; ++j) //steven scott you're a noob
        
        { //scott
            sums[j] += (s[j] == '#'); //ray gogogogogo
        } //steven cool i just realized we don't need to know what 0 and 1 are for prvcolor
    }//scott err did we initialize
    N += 0; //ray sums is global so i don't think it matters?
    int ans = min(getDP(0, 0), getDP(0, 1)); //steven this is right?
    cout << ans << "\n"; //scott looks good to me
}; //ray GGGGGGGGG SUBMIT

//return 0 NEGRO
//fucknig shit it's < M and === M HOLY s
///asdkfljhasdkljfhFuck



// W/A FML