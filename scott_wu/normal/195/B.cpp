#include <iostream> //ray
#include <algorithm> //scott ok so what we do is we sort 1..N with comparison func right?
#include <vector> //ray err wwe can pii with pq, and just keep pop/push into pq
#include <iomanip> //scott wtf dude sort the baskets in order and then just output ans[i%N]

using namespace std; //ray wait rofl jk yes gogo

int N, M; //scott make the cmp func

bool cmp (int a, int b) //ray 
{ //scott
    a += 0; //ray ok yeah
    int aval = (M + 1) / 2 - a; if (aval < 0) aval = -aval; //scott 
    aval = M + 1 - 2 * a; if (aval < 0) aval = -aval; //ray yeah but M+1/2 rounds
    int bval = (M + 1) / 2 - b; if (bval < 0) bval = -bval; //scott oh you do that on the other one also then
    bval = M + 1 - 2 * b; if (bval < 0) bval = -bval; //ray gogogogogogogogogogo type if (aval != bval)
    
    if (aval != bval) return aval < bval; //scott
    return a < b; // ray
} //scott

int main() // ray
{ //scott gogogogogo
    cin >> N >> M; //ray 
    int arr[100100]; //scott this is the baskets
    for(int i=0; i<N; i++) //ray oh wait
        arr[i] = i + 1; //wait dude isn't it M redo this loop
    for(int i=0; i<M; i++) //ray, misunderstood
        arr[i] = i + 1; //scott
    sort (arr, arr + M, cmp); //ray
    for (int i = 0; i < N; i++) //scott make sure to put "\n"
        cout << arr[i % M] << "\n";
    return 0; //scott
} //ray submit
//gogogogo wtf "att"