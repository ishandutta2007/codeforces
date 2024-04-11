#include <iostream> //scott http://www.codeforces.com/problemset/problem/155/B
#include <algorithm> //ray dawg lemme pick problem
#include <iomanip> //scott
#include <cstring> //ray, ok this is not hard just pick the cards with highest bi
#include <string> //scott

using namespace std; //ray, er w/e just sort by bi then ai;

int N; //scott

typedef pair<int,int> pii; //ray 
pair <int, int> dawg[1100]; //scott this is b, a

int main()  //ray yeah
{ cin >> N; //scott
    for(int i=0; i<N; i++) //ray oh wait shit w/e
        cin >> dawg[i].second >> dawg[i].first; //scott wait is something wrong
    
    for (int i=0; i<N; i++) dawg[i].second = dawg[i].second; //ray
    sort (dawg, dawg + N); //scott

    int nmove = 1; // ray
    int ans = 0; //scott so we just loop down to
    for (int i=0; i<N; i++) { //ray yeah fuck hella spacing gogo i have 1 minute left
    } for (int i = N - 1; i >= N - nmove && i >= 0; i--) { //scott what are you doing dude
        nmove = nmove - 1 +dawg[i].second; //ray sorry mandelbrot ended
        nmove = nmove + 1 - dawg[i].second + dawg[i].first; //scott what are you doing dude
        nmove --; //ray oh wait jk
        nmove++; //scott dude look at my loop with i, this is already taken care of, also dawg[i].first is b[i]
        ans += dawg[i].second; //wtf are you doing dude
    } //ray lol
    cout << ans << "\n"; //scott


} // ray