//read b.
//done
#include <cstdio> //steven, sry still using c++.
#include <iostream> //julia fast learner B)
#include <set> //steven, how do you want to do this i think just <set> spam. set == treeset
using namespace std;//julia dude what's a set oh
#include <algorithm> //steven, we will insert all the points in a set<pii> and all the x's in a set<int> and all the y's in a set<int> or is there a faster way

//julia what's a pii oh what do i type for this line
typedef pair<int, int> pii; //steven this is a pii. leave it blank it's chill

int main() //julia 
{ //steven    
set<int> xs;//julia this feels so wrong lol
set<int> ys; //steven this is how a set is constructed, we need set<pii> too 
set<pii> pairs;//julia
for(int i = 0; i < 8; ++i) {//steven, nvm keep going cin >> lol you need to have a int x, y;
    int x,y; //julia  there we go
    cin >> x >> y; //steven
    xs.insert(x);//julia
    ys.insert(y); //steven, it's insert sry and to construct a pii do pii(x, y), we actually need the pairs set to make sure no repeats or else we have like 0 0, 0 0, 0 0, 1 1, 1 1, 2 2 x 3 
pairs.insert(pii(x,y));//julia why do we need pairs?? oh good catch
}//steven we need to first check int(pairs.size()) == 8, then iterate over x's and stuff
if (pairs.size()==8 && xs.size()==3 && ys.size()==3) { //julia
    #define repi(i,a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i) //steven, repi is for each loop. make an external counter too so we can tell which one is the middle. like int i = 0; repi(x, xs) { int j = 0; repi(y, ys) { ... ++j; } ++i; } ... so we check (if (i == 1 && j == 1) continue; or something
    int i = 0; // julia
    repi(x, xs) { //steven
    int j = 0; // julia
        repi(y, ys) { //steven, first increment j, then check (i == 1 && j == 2) hmm
        ++j;
            if (i == 1 && j == 2) { //steven just continue cause i == 1 && j == 2 means it's the middle point that we skip we do that check later for i != 1 || j != 2 (in the else)continue the repi for loop. repi is a for loop it's a macro for a for loop we can continue it type "continue;" we skip the i == 1 && j == 2 case cause that's when we're at the center
                continue; //i'm still confused
            } //steven, now we check that pii(*x, *y) is in the thingy, we could've checked xs.size and ys.size at the end too
else{//jul  ia
    if (pairs.find(pii(*x, *y)) == pairs.end()) { //steven, it is not in the set cause it coudln't find it
        cout << "ugly"; //awwww yeahhh right direction don't even think about trying to convince me otherwise
        return 0; //steven, i think i get what you were doing earlier lol sorry your way was prolly better
}//julia closes if
} //steven, just checking the middle point not there is the cleanest way lol, we have hella }}}}}}}}} we need still
}//julia closes repi y
++i;
} //steven, this closes the repi x, we need to cout before the end of the if, and then do an else
cout<<"respectable";//julia yeaahhh
} else cout << "ugly"; //steven btw cout usually needs \n at the end except codeforces doesn't care
}//donee
//WA on test 1 forgot to inc i.