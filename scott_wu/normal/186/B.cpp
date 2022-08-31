//Richard: moo
//scott moo
//Richard: turn order?
//scott shouldn't matter much? i can go first
//Richard: ok, you go first

#include <iostream> //scott ok so this should be pretty easy, just compute the max of the two possibilities
#include <algorithm> //Richard: then sort a bunch of pairs?
#include <cstdio> //scott yeah sounds good, we need EPS when checking though
#include <cstring> //Richard: doubles and 1e-9 ok?
#include <vector> //scott wait actually we don't need EPS if we multiply everything by 100 we can just work with int
using namespace std; //yeah, just multiply the first 100, second by k
const double EPS = 1e-9; //scott in case we need it

int n; //Richard: ok, let's sort with ints, but output using %lf + EPS
int t1, t2, k; //scott ok sounds good

pair<int,int> lis[12345]; //Richard: ok

int a[1100], b[1100]; //scott is this all we need?

int main() {//Richard: seems ok, at the end of the way we just output lis
    cin >> n >> t1 >> t2 >> k; //scott so how are we doing lis? index then score?
    for(int i = 0; i < n; ++i) {//Richard: -score, then index, so we can just sort, and flip things back
        cin >> a[i] >> b[i]; //scott ok now we compute lis right
        lis[i].first = max(a[i] * t1 * k + b[i] * t2 * 100, b[i] * t1 * k + a[i] * t2 * 100); //Richard: is this ok?
        lis[i].first = max(a[i] * t1 * (100 - k) + b[i] * t2 * 100, b[i] * t1 * (100 - k) + a[i] * t2 * 100); //scott i think it's 100 - k? cause it decreases by k percent
        lis[i] = make_pair(-lis[i].first, i); //Richard: yeah, make sense...
    } //scott
    sort(lis, lis + n); //Richard, print using printf and double?

    for (int i = 0; i < n; i++) { //scott you print make sure it's exactly 2 digits 
        //printf("%0.2lf %d\n", double(-lis[i].first) / double(100) + EPS, i + 1); //Richard
        printf("%d %0.2lf\n", lis[i].second + 1, double(-lis[i].first) / double(100) + EPS); //scott is this right?
    } //Richard: seems more right...
    return 0; //scott
}//Richard: bombs away...
//submit