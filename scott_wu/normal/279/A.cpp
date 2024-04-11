//http://codeforces.com/contest/279/problem/A
#include <cstdio> //steven
#include <iostream> //scott how do you do this

using namespace std; //steven it's math

int main() //scott seriously tthough
{ // steven first look at max(abs(x),abs(y)) then casework on quadrant
    int x, y; cin >> x >> y; //scott
    int xx = x > 0 ? x : -x; //steven, does iostream include abs
    int yab = max (y, -y); //scott idk how to do this
    int sxy = xx + yab; //steven this is an appropriate var name, Sum of X and Y.
    sxy -= (xx ^ xx); //scott what is this var for
    int imessedup;//steven we need to find the square it's on there's a buncho f concentric squares of side .5, 1.5, etc
    
    int hlen = max (x, y); //sco
    if (x > 0) { //steven, hlen = x?.
        for (int i = 0; i < x; i++) //scott you do something
            ;//steven, let's find side length of square.
        hlen = hlen + hlen - (hlen & hlen) ^ (hlen | hlen) ^ hlen; //scott wait i can do it
    } //steven, let's simulate the horse guy. N <= 100.
    int jkicantdoit; //scott
    bool visited[300][300]; //steven, we'll keep track of the squares he's visited.
    int xcur = 0, ycur = 0, nturn = 0; //scott how do you do that
    int mx[4] = {1, 0, -1, 0}, my[4] = {0, 1, 0, -1}; //steven we'll add 110 to coordinates so we have positive indices.
    int cdir = 0, clen = 1; //scott current direction, current length to travel
    while (xcur != x || ycur != y) { //steven, wait what thx
    break;} //scott let me do this
    int numsteps = 0; //steven increment clen when cdir becomes 2?
    while (true) //scott no what we'll do is we just follow
 { //steven use a for loop/
    for (int i = 0; i < clen; i++) //scott
    {//steven ik. we don't need visit
        xcur += mx[cdir]; ycur += my[cdir]; //scott now check x,y
        if(x == xcur && y == ycur) {//steven
        cout << nturn << "\n"; //scott
        return 0; //steven, finish.
        }if (x == 0 && y == 0) {cout << "0\n"; return 0;} //scott now change cdir and clen and nturn
    } //steven nah dawg i see what you did.
        cdir = (cdir + 1) % 4; //scott
        if (cdir == 2) { //steven 
        clen++;} if (cdir == 0) clen++; //scott now nturn
        ++nturn; //steven, almost forgot.
        jkicantdoit++; //scott we don't have anything else right
        imessedup = 4; //steven don't think so
    } //scott yay
    return 0; //steven jk this indenting is killing me
}//scott