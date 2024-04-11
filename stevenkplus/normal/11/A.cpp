/* sup -steven
yo - scott
nom - mark*/
#include <cstdio> //steven spelled it right just keep track of previous and iterate don't need array
#include <iostream> //scott yeah so you can only increase so simple greedy works
#include <algorithm>

using namespace std; //steven i think we don't need long long

int main() {//scott yeah i don't think we need it
    int n, d; // mark
    scanf("%d %d", &n, &d); //steven
    int lval = 0; //scott last value, skip over this part in i=0
    int numinc = 0; //steven this is the answer we print out. ^ we don't need to skip anything cause it's 0
    for(int i = 0; i < n; i++)  { // I got skipped :P, mark
        int curval; //scott current value
        //sorry mark i forgot we had 3 people i'll skip this turn cause i'm a bad person
        scanf("%d", &curval);
/*        while (curval <= lval) { //scott increase numinc and add to curval
            curval += d; //steven need to inc
            numinc++;
        } //scott
        lval = curval; //steven
    } // mark oh jk
    cout << numinc << "\n"; //scott should be fine
    return 0; //steven cout works fine i think
}
//gogogo
//steven i submitTLE
//wait the while loop takes too long oops
//yarp, fix or fail?
//darn*/

//scott start here
        int need = lval + 1; //steven, too lazy to do math er 
        int incs = need > curval ? (need - curval + d - 1) / 2 : 0; //we
        incs = need > curval ? (need - curval + d - 1) / d : 0; // scott
        numinc += incs; //steven
        lval = curval + incs * d; // mark
    } //scott
    printf("%d\n", numinc); //steven don't forget to return 0     :D
    return 0;
        } //scott