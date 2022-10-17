/*

http://codeforces.com/problemset/problem/474/B

saketh: when you write a comment include your name

order is saketh, dasith, robert

*/

using namespace std; //saketh: go
//int main(){ //pls no funcsion   // robert: We need to include algorithms and vector (maybe)
#include <iostream> // saketh: algorithms is for pussies
#include <vector> //whoops I thought it was assume
/* #include <algorithms> // robert: because I'm a pussy */ // saketh: no fk u
/* #include <algorithms> //I sabe u */

int main() { // robert: YAY DASITH I LOVE YOU
    int N, M; // saketh: turns out you cant uninclude stuff, you guys are lucky
    cin >> N; //dasith: l 1
    int a[100001], q[100001]; // robert
    for(int i=0; i<N; i++){ // saketh: mfw we included vector
        cin >> a[i];} //no one saw that
    cin >> M; // robert
    for(int i=0; i<M; i++){ // saketh: i am dosit
        cin >> q[i];} //dasith: am socket
    string RobertIsClueless = "What the fuck do I do"; // robert: Fuck you for not including maps and all that other shit

    /*for(bool maps = true, dumb = true; true;) if(maps == dumb) return 0; // saketh: :^)*/ //ya it does socket u r sod
    // #include <map>   // Robert: I hope this is syntactically allowed :)  You guys forgot to comment my shit out
    
    int p[100001]; // socket: it's not so let's make a prefix sum array and binary search it
    
    for(int i=0;i<N;i++){ // dasith: am dosit
        p[i] = a[i] + (i?p[i-1]:0);  //socket: is this even right
    } // y didn't u close the loop 
    
    for (int i = 0; i < M; i++) { // robert: now we go through the juicy things and do O(lgn) search through p
        int lo = 0, hi = N-1; // saketh: if we rally code a binary search right on the first attempt i will sacrifice a suckling pig to satan
        while (hi - lo > 0){ //dosit: shit u guys left me with the hard part  // robert: I wasn't sure if dosit was done :D
            int mid = (lo+hi)/2; //socket: is (hi - lo > 0) some sort of mutant form of lo < hi
            // if(mid+1<=100001 && a[mid] < q[i] && a[mid+1] > q[i]){ //dosit is guessing   robert: I think we should let socket do this
            if(q[i] <= p[mid]) hi = mid; //socket: you guys get to do the other half
            // else if(q[i] > p[mid]) lo=mid; //man wtf   // man lo = mid+1;
            // socket's turn is going to be a noble sacrifice to vanquish <algorithms>
/*            else if(q[i] > p[mid]) lo=mid+1; // oks
        }*/ // you didn't need that else if, just else
        //saketh; no lol it's not just unneeded, it's actually wrong
        if(q[i]>p[mid]) lo=mid+1; //third try shit fuck
        } // Robert: yay the easy line
        // return 1; // saketh: uhh im gonna guess      robert: why the fuck are you returning 1, asshole
        //wait what what this is my code
        cout << lo+1 << "\n"; // saketh: sorry I got confused
        } //dosit
        // I think we only need to return 0 now?
        
    cout.flush(); // socket: ya we done
    return 0;}//wut
// yay that's a wrap