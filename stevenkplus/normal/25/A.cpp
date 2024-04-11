#include <cstdio> //steven, http://codeforces.com/problemset/problem/25/A this is a page 1 problem. NO MINE
#include <iostream> // scott
#include <cstring> //ray
#include <algorithm> // steven, i can start coding before you finish right? 
#include <vector> //scott

using namespace std; //ray


const int MAXN = 110; //steven
int N; //scott

int main(){ //ray
    int *ar = new int[MAXN]; //steven
    cin >> N; //scott
    for(int i=0; i<N; i++) { //ray, nig what are you doing
        cin >> ar[i]; //steven, nigga what
    }//scott
    int r0 = -1, r1 = -1; //ray
    int numodd = 0; //steven, i don't get what R0 is
    
    for (int i = 0; i < N; i++) //scott r0 is location of even?
    { //ray, yes
        if (ar[i] % 2 == 0) { //steven ok
            r0 = i+1;//scott go ray
        }else{ // ray
            r1 = i + 1; //steven
            numodd++; //scott
        } //ray
    } //steven
    if (numodd == 1) //scott
    { //ray
        cout << r1 << endl; //steven
    } else { //scott
        cout << r0 << endl; } //ray
    return 0; //steven
}//sc

//new lines for you guys - steven